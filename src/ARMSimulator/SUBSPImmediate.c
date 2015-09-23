/*  
    GDB RSP and ARM Simulator

    Copyright (C) 2015 Wong Yan Yin, <jet_wong@hotmail.com>,
    Jackson Teh Ka Sing, <jackson_dmc69@hotmail.com>

    This file is part of GDB RSP and ARM Simulator.

    This program is free software, you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY, without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with This program.  If not, see <http://www.gnu.org/licenses/>.
*/



#include "SUBSPImmediate.h"
#include "SUBImmediate.h"
#include "ITandHints.h"
#include "StatusRegisters.h"
#include "ARMRegisters.h"
#include "getAndSetBits.h"
#include "getMask.h"
#include "ModifiedImmediateConstant.h"
#include "ConditionalExecution.h"
#include "MemoryBlock.h"
#include <stdio.h>


/*SUB (SP minus immediate) Encoding T1
    SUB<c> SP,SP,#<imm7>

  31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
  |1  0  1  1| 0  0  0  0| 1|         imm7       |                unused               |

  setflags = FALSE

where:
          S               If present, specifies that the instruction updates the flags. Otherwise, the instruction does not
                          update the flags.

          <c><q>          See Standard assembler syntax fields on page A6-7.

          <Rd>            Specifies the destination register. If <Rd> is omitted, this register is SP.

          <const>         Specifies the immediate value to be added to the value obtained from SP. Allowed values
                          are multiples of 4 in the range 0-508 for encoding T1 and any value in the range 0-4095 for
                          encoding T3. See Modified immediate constants in Thumb instructions on page A5-15 for
                          the range of allowed values for encoding T2.

          When both 32-bit encodings are available for an instruction, encoding T2 is preferred to
          encoding T3 (if encoding T3 is required, use the SUBW syntax).
*/
void SUBSPImmediateT1(uint32_t instruction)
{
  uint32_t imm7 = getBits(instruction,22,16);

  if(inITBlock())
  {
    if( checkCondition(cond) )
      coreReg[SP] = coreReg[SP] - ( imm7 << 2);

    shiftITState();
    coreReg[PC] += 2;
  }
  else
  {
    coreReg[SP] = coreReg[SP] - ( imm7 << 2);
    coreReg[PC] += 2;
  }
}


/* SUB (SP minus immediate) Encoding T2

SUB{S}<c>.W <Rd>,SP,#<const>

31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
|1  1  1  1 0 |i||0| 1  1  0  1 |S| 1  1  0  1 |0|  imm3   |    Rd   |     imm8      |

where :
          S             If present, specifies that the instruction updates the flags. Otherwise, the instruction does not
                        update the flags.

          <c><q>        See Standard assembler syntax fields on page A6-7.

          <Rd>          Specifies the destination register. If <Rd> is omitted, this register is SP.

          <const>       Specifies the immediate value to be added to the value obtained from SP. Allowed values
                        are multiples of 4 in the range 0-508 for encoding T1 and any value in the range 0-4095 for
                        encoding T3. See Modified immediate constants in Thumb instructions on page A5-15 for
                        the range of allowed values for encoding T2.

                        When both 32-bit encodings are available for an instruction, encoding T2 is preferred to
                        encoding T3 (if encoding T3 is required, use the SUBW syntax).
*/
void SUBSPImmediateT2(uint32_t instruction)
{
  uint32_t imm8 = getBits(instruction, 7, 0);
  uint32_t Rd = getBits(instruction, 11, 8);
  uint32_t Rn = getBits(instruction, 19, 16);
  uint32_t imm3 = getBits(instruction, 14, 12);
  uint32_t statusFlag = getBits(instruction, 20, 20);

  uint32_t i = getBits(instruction, 26, 26);
  uint32_t bit7 = getBits(instruction, 7, 7);
  uint32_t temp = (i << 3 ) | imm3;
  uint32_t modifyControl = (temp << 1) | bit7;

  uint32_t ModifiedConstant = ModifyImmediateConstant(modifyControl, imm8, 0);

  if(inITBlock())
  {
    if( checkCondition(cond) )
      executeSUBImmediate(Rn, Rd, ModifiedConstant, statusFlag);
    shiftITState();
  }
  else
    executeSUBImmediate(Rn, Rd, ModifiedConstant, statusFlag);

  coreReg[PC] += 4;
}


/* SUB (SP minus immediate) Encoding T3

SUBW<c> <Rd>,SP,#<imm12>

31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
|1  1  1  1 0 |i||1| 0  1  0  1 |0| 1  1  0  1 |0|  imm3   |    Rd   |     imm8      |

where :
          S             If present, specifies that the instruction updates the flags. Otherwise, the instruction does not
                        update the flags.

          <c><q>        See Standard assembler syntax fields on page A6-7.

          <Rd>          Specifies the destination register. If <Rd> is omitted, this register is the same as <Rn>.

          <Rn>          Specifies the destination register. If <Rd> is omitted, this register is SP.

          <const>       Specifies the immediate value to be added to the value obtained from SP. Allowed values
                        are multiples of 4 in the range 0-508 for encoding T1 and any value in the range 0-4095 for
                        encoding T3. See Modified immediate constants in Thumb instructions on page A5-15 for
                        the range of allowed values for encoding T2.

                        When both 32-bit encodings are available for an instruction, encoding T2 is preferred to
                        encoding T3 (if encoding T3 is required, use the SUBW syntax).
*/
void SUBSPImmediateT3(uint32_t instruction)
{
  uint32_t imm8 = getBits(instruction, 7, 0);
  uint32_t Rd = getBits(instruction, 11, 8);
  uint32_t Rn = getBits(instruction, 19, 16);
  uint32_t imm3 = getBits(instruction, 14, 12);

  uint32_t i = getBits(instruction, 26, 26);
  uint32_t temp = (i << 3 ) | imm3;

  uint32_t ModifiedConstant = temp << 8 | imm8;

  if(inITBlock())
  {
    if( checkCondition(cond) )
      executeSUBImmediate(Rn, Rd, ModifiedConstant, 0);
    shiftITState();
  }
  else
    executeSUBImmediate(Rn, Rd, ModifiedConstant, 0);

  coreReg[PC] += 4;
}
