#include "StatusRegisters.h"
#include <stdio.h>
#include <assert.h>

/*
  This function will initialize all the status register to 0
  
  31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
 |N |Z |C |V |                           Reserved                                      |
  
  
  [31]	N	
        Negative or less than flag:
                                      1 = result negative
                                      0 = result positive.
        
  [30]	Z	
        Zero flag:
                    1 = result of 0
                    0 = nonzero result.
                    
  [29]	C	(unsigned overflow)
        Carry or borrow flag:
                                1 = carry true or borrow false
                                0 = carry false or borrow true.
                                
  [28]	V	(signed overflow)
        Overflow flag:
                        1 = overflow
                        0 = no overflow.
                        
  [27:0]	-	Reserved ( The bits are defined as UNK/SBZP )
          
*/
void initStatusRegister()
{
  StatusRegisters = 0x0000;
    
}


bool isNegative()
{
  if( getBits(StatusRegisters, 31, 31) )
    return true;
  else
    return false;
}

bool isZero()
{
  if( getBits(StatusRegisters, 30, 30) )
    return true;
  else
    return false;
}

bool isCarry()
{
  if( getBits(StatusRegisters, 29, 29) )
    return true;
  else
    return false;
}

bool isOverflow()
{
  if( getBits(StatusRegisters, 28, 28) )
    return true;
  else
    return false;
}

void setCarryFlag()
{
  StatusRegisters = StatusRegisters | 0x20000000;
}

void resetCarryFlag()
{
  StatusRegisters = StatusRegisters & 0xdfffffff;
}

void setNegativeFlag()
{
  StatusRegisters = StatusRegisters | 0x80000000;

}

void resetNegativeFlag()
{
  StatusRegisters = StatusRegisters & 0x7fffffff;
}

void setZeroFlag()
{
  StatusRegisters = StatusRegisters | 0x40000000;

}

void resetZeroFlag()
{
  StatusRegisters = StatusRegisters & 0xbfffffff;
}

void setOverflowFlag()
{
  StatusRegisters = StatusRegisters | 0x10000000;

}

void resetOverflowFlag()
{
  StatusRegisters = StatusRegisters & 0xefffffff;
}


void updateZeroFlag(uint32_t value)
{
  if(value == 0)
    setZeroFlag();
  else
    resetZeroFlag();
}

void updateNegativeFlag(uint32_t value)
{
  if( getBits(value,31,31) == 1)
    setNegativeFlag();
  else
    resetNegativeFlag();
}

/* This will update the carry flag based on the addition result
   of value1 and value2

*/
void updateCarryFlagAddition(uint32_t value1, uint32_t value2)
{
  int bit0 = 0, intermediateCarry = 0, i,adder;
  
  for(i = 0; i < 32; i++)
  {
    adder = intermediateCarry + getBits(value1,bit0,bit0) + getBits(value2,bit0,bit0);
    if(adder >= 2)
      intermediateCarry = 1;
    else
      intermediateCarry = 0;
    bit0++;
  }

  if( intermediateCarry == 1)
    setCarryFlag();
  else
    resetCarryFlag();
}


/* This will update the carry flag based on the subtraction result
   of value1 and value2

*/
void updateCarryFlagSubtraction(uint32_t value1, uint32_t value2)
{
  if( value1 >= value2)
    setCarryFlag();
  else
    resetCarryFlag();
}


/*
1. If the sum of two numbers with the sign bits off yields a result number
   with the sign bit on, the "overflow" flag is turned on.

   0100 + 0100 = 1000 (overflow flag is turned on)

2. If the sum of two numbers with the sign bits on yields a result number
   with the sign bit off, the "overflow" flag is turned on.

   1000 + 1000 = 0000 (overflow flag is turned on)
*/
void updateOverflowFlag(uint32_t value1, uint32_t value2)
{
  int carryFromBit30 = getCarry(value1,value2,30);
  int carryFromBit31 = getCarry(value1,value2,31);
  
  if(   ( carryFromBit30 == 1 && carryFromBit31 == 0) || (carryFromBit30 == 0 && carryFromBit31 == 1)   )
    setOverflowFlag();
  else
    resetOverflowFlag();
}


/*  This will get the carry from the addition of the two value  
 *
 *  Return: the carrybit from the result of addition
 */
int getCarry(uint32_t value1, uint32_t value2, int bitSize)
{
  if( getBits(value1,bitSize,bitSize) == 1 && getBits(value2,bitSize,bitSize) == 1 )
    return 1;
  else 
    return 0;
}

