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


#include "Thumb32bitsTable.h"
#include <stdio.h>


void initThumb32Table()
{
  int i,j,k;
  uint32_t dummy;

  Thumb32Table[0b1000000000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000000010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000000010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000000100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000000110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000001000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000001010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000001100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000001110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000010000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000010010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000010100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000010110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000011000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000011010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000011100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000011110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000011110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000100000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000100010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000100100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000100110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000101000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000101010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000101100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000101110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000110000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000110010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000110100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000110110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000111000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000111010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000111100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1000111110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010000000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010000010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010000010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010000100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010000110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010001000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010001010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010001100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010001110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010010000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010010010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010010100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010010110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010011000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010011010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010011100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010011110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010011110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010100000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010100010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010100100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010100110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010101000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010101010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010101100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010101110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010110000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010110010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010110100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010110110] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010111000] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010111010] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010111100] = executeDataProcessingModifiedImmediate;
  Thumb32Table[0b1010111110] = executeDataProcessingModifiedImmediate;
  //
  Thumb32Table[0b1001000000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001000010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001000010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001000100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001000110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001001000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001001010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001001100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001001110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001010000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001010010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001010100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001010110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001011000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001011010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001011100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001011110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001011110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001100000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001100010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001100100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001100110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001101000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001101010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001101100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001101110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001110000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001110010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001110100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001110110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001111000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001111010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001111100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1001111110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011000000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011000010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011000010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011000100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011000110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011001000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011001010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011001100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011001110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011010000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011010010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011010100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011010110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011011000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011011010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011011100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011011110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011011110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011100000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011100010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011100100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011100110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011101000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011101010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011101100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011101110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011110000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011110010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011110100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011110110] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011111000] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011111010] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011111100] = executeDataProcessingPlainImmediate;
  Thumb32Table[0b1011111110] = executeDataProcessingPlainImmediate;
  //
  Thumb32Table[0b0101000000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101000111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101001111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101010111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101011111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101100111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101101111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101110111] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111000] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111001] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111010] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111011] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111100] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111101] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111110] = executeDataProcessingShiftedRegister;
  Thumb32Table[0b0101111111] = executeDataProcessingShiftedRegister;
  //
  Thumb32Table[0b1101000000] = executeDataProcessingRegister;
  Thumb32Table[0b1101000001] = executeDataProcessingRegister;
  Thumb32Table[0b1101000010] = executeDataProcessingRegister;
  Thumb32Table[0b1101000011] = executeDataProcessingRegister;
  Thumb32Table[0b1101000100] = executeDataProcessingRegister;
  Thumb32Table[0b1101000101] = executeDataProcessingRegister;
  Thumb32Table[0b1101000110] = executeDataProcessingRegister;
  Thumb32Table[0b1101000111] = executeDataProcessingRegister;
  Thumb32Table[0b1101001000] = executeDataProcessingRegister;
  Thumb32Table[0b1101001001] = executeDataProcessingRegister;
  Thumb32Table[0b1101001010] = executeDataProcessingRegister;
  Thumb32Table[0b1101001011] = executeDataProcessingRegister;
  Thumb32Table[0b1101001100] = executeDataProcessingRegister;
  Thumb32Table[0b1101001101] = executeDataProcessingRegister;
  Thumb32Table[0b1101001110] = executeDataProcessingRegister;
  Thumb32Table[0b1101001111] = executeDataProcessingRegister;
  Thumb32Table[0b1101010000] = executeDataProcessingRegister;
  Thumb32Table[0b1101010001] = executeDataProcessingRegister;
  Thumb32Table[0b1101010010] = executeDataProcessingRegister;
  Thumb32Table[0b1101010011] = executeDataProcessingRegister;
  Thumb32Table[0b1101010100] = executeDataProcessingRegister;
  Thumb32Table[0b1101010101] = executeDataProcessingRegister;
  Thumb32Table[0b1101010110] = executeDataProcessingRegister;
  Thumb32Table[0b1101010111] = executeDataProcessingRegister;
  Thumb32Table[0b1101011000] = executeDataProcessingRegister;
  Thumb32Table[0b1101011001] = executeDataProcessingRegister;
  Thumb32Table[0b1101011010] = executeDataProcessingRegister;
  Thumb32Table[0b1101011011] = executeDataProcessingRegister;
  Thumb32Table[0b1101011100] = executeDataProcessingRegister;
  Thumb32Table[0b1101011101] = executeDataProcessingRegister;
  Thumb32Table[0b1101011110] = executeDataProcessingRegister;
  Thumb32Table[0b1101011111] = executeDataProcessingRegister;
  //
  Thumb32Table[0b1000000001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000000011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000000101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000000111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000001001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000001011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000001101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000001111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000010001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000010011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000010101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000010111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000011001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000011011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000011101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000011111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000100001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000100011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000100101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000100111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000101001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000101011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000101101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000101111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000110001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000110011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000110101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000110111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000111001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000111011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000111101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1000111111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001000001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001000011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001000101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001000111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001001001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001001011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001001101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001001111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001010001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001010011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001010101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001010111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001011001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001011011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001011101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001011111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001100001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001100011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001100101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001100111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001101001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001101011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001101101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001101111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001110001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001110011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001110101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001110111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001111001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001111011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001111101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1001111111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010000001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010000011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010000101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010000111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010001001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010001011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010001101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010001111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010010001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010010011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010010101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010010111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010011001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010011011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010011101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010011111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010100001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010100011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010100101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010100111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010101001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010101011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010101101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010101111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010110001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010110011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010110101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010110111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010111001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010111011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010111101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1010111111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011000001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011000011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011000101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011000111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011001001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011001011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011001101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011001111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011010001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011010011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011010101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011010111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011011001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011011011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011011101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011011111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011100001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011100011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011100101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011100111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011101001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011101011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011101101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011101111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011110001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011110011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011110101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011110111] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011111001] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011111011] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011111101] = executeBranchesAndMiscellaneousControl;
  Thumb32Table[0b1011111111] = executeBranchesAndMiscellaneousControl;
  //
  Thumb32Table[0b1100001010] = executeLoadWord;
  Thumb32Table[0b1100011010] = executeLoadWord;
  Thumb32Table[0b1100101010] = executeLoadWord;
  Thumb32Table[0b1100111010] = executeLoadWord;
  Thumb32Table[0b1100001011] = executeLoadWord;
  Thumb32Table[0b1100011011] = executeLoadWord;
  Thumb32Table[0b1100101011] = executeLoadWord;
  Thumb32Table[0b1100111011] = executeLoadWord;
  //
  Thumb32Table[0b1101100000] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100001] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100010] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100011] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100100] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100101] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100110] = executeMultiplyAccumulate;
  Thumb32Table[0b1101100111] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101000] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101001] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101010] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101011] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101100] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101101] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101110] = executeMultiplyAccumulate;
  Thumb32Table[0b1101101111] = executeMultiplyAccumulate;
  //
  Thumb32Table[0b1101110000] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110001] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110010] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110011] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110100] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110101] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110110] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101110111] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111000] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111001] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111010] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111011] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111100] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111101] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111110] = executeLongMultiplyAccumulateDivide;
  Thumb32Table[0b1101111111] = executeLongMultiplyAccumulateDivide;
  //
  dummy = 0b0100000000;
  for(i = 0; i <= 0b11; i ++)
  {
    dummy = setBits(dummy, i, 5, 4);
    for(j = 0; j <= 0b111; j ++)
    {
      dummy = setBits(dummy,j,2,0);
      Thumb32Table[dummy] = executeLoadStoreMultiple;
    }
  }
  //
  dummy = 0b1100000000;
  for(i = 0; i <= 0b111; i ++)
  {
    dummy = setBits(dummy, i, 4, 2);
    for(j = 0; j <= 0b1; j ++)
    {
      dummy = setBits(dummy,j,0,0);
      Thumb32Table[dummy] = executeStoreSingleDataItem;
    }
  }
  //
  dummy = 0b1100000010;
  for(i = 0; i <= 0b11; i ++)
  {
    dummy = setBits(dummy,i,5,4);
    for(j = 0; j <= 0b1; j++)
    {
      dummy = setBits(dummy,j,0,0);
      Thumb32Table[dummy] = executeLoadByteMemoryHints;
    }
  }
  //
  dummy = 0b0100001000;
  for(i = 0; i <= 0b11; i ++)
  {
    dummy = setBits(dummy,i,5,4);
    for(j = 0; j <= 0b11; j++)
    {
      dummy = setBits(dummy,j,2,1);
      for(k = 0; k <= 0b1; k++)
      {
        dummy = setBits(dummy,k,0,0);
        Thumb32Table[dummy] = executeLoadStoreDualTableBranch;
      }
    }
  }
  //
  dummy = 0b1100000110;
  for(i = 0; i <= 0b11; i ++)
  {
    dummy = setBits(dummy,i,5,4);
    for(j = 0; j <= 0b1; j++)
    {
      dummy = setBits(dummy,j,0,0);
      Thumb32Table[dummy] = executeLoadHalfword;
    }
  }
}




void initThumb32bitsDataProcessingShiftedRegister()
{
  // AND Register T2 annd TST T2
  int i;

  for(i = 0b0000000000000; i < 0b0001000000000; i++)
  {
    if((i & 0b0000000011110) != 0b11110)
      Thumb32DataProcessingShiftedRegister[i] = ANDRegisterT2;
    else
    {
      if((i & 0b1) == 0b1)
        Thumb32DataProcessingShiftedRegister[i] = TSTRegisterT2;
    }
  }
  // BIC Register T2
  for(i = 0b0001000000000; i < 0b0010000000000; i++)
    Thumb32DataProcessingShiftedRegister[i] = BICRegisterT2;
  // Move Register and Immediate Shifts and ORR Register T2
  for(i = 0b0010000000000; i < 0b0011000000000; i++)
  {
    if((i & 0b0000111100000) != 0b111100000)
      Thumb32DataProcessingShiftedRegister[i] = ORRRegisterT2;
    else
      Thumb32DataProcessingShiftedRegister[i] = executeMoveRegisterAndImmediateShifts;
  }
  // MVN Register T2 and ORN Register T1
  for(i = 0b0011000000000; i < 0b0100000000000; i++)
  {
    if((i & 0b0000111100000) != 0b111100000)
      Thumb32DataProcessingShiftedRegister[i] = ORNRegisterT1;
    else
      Thumb32DataProcessingShiftedRegister[i] = MVNRegisterT2;
  }
  // EOR Register T2 and TEQ Register T1
  for(i = 0b0100000000000; i < 0b0101000000000; i++)
  {
    if((i & 0b0000000011110) != 0b11110)
      Thumb32DataProcessingShiftedRegister[i] = EORRegisterT2;
    else
    {
      if((i & 0b1) == 0b1)
        Thumb32DataProcessingShiftedRegister[i] = TEQRegisterT1;
    }
  }
  // ADD Register T3 and CMN Register T2
  for(i = 0b1000000000000; i < 0b1001000000000; i++)
  {
    if((i & 0b0000000011110) != 0b11110)
    {
      if((i & 0b0000110100000) != 0b110100000)    // Rd != 1111 and Rn != 1101
        Thumb32DataProcessingShiftedRegister[i] = ADDRegisterT3;
      else
        Thumb32DataProcessingShiftedRegister[i] = ADDSPRegisterT3;
    }
    else
    {
      if((i & 0b1) == 0b1)
        Thumb32DataProcessingShiftedRegister[i] = CMNRegisterT2;
    }
  }
  // ADC Register T2
  for(i = 0b1010000000000; i < 0b1011000000000; i++)
    Thumb32DataProcessingShiftedRegister[i] = ADCRegisterT2;
  // SBC Register T2
  for(i = 0b1011000000000; i < 0b1100000000000; i++)
    Thumb32DataProcessingShiftedRegister[i] = SBCRegisterT2;
  // SUB Register T2 and CMP Register T2
  for(i = 0b1101000000000; i < 0b1110000000000; i++)
  {
    if((i & 0b0000000011110) != 0b11110)
    {
      if((i & 0b0000110100000) != 0b110100000)    // Rd != 1111 and Rn != 1101
        Thumb32DataProcessingShiftedRegister[i] = SUBRegisterT2;
      else
        Thumb32DataProcessingShiftedRegister[i] = SUBSPRegisterT1;
    }
    else
    {
      if((i & 0b1) == 0b1)
        Thumb32DataProcessingShiftedRegister[i] = CMPRegisterT3;
    }
  }
  // RSB Register T1
  for(i = 0b1110000000000; i < 0b1111000000000; i++)
    Thumb32DataProcessingShiftedRegister[i] = RSBRegisterT1;
}


void initThumb32bitsMoveRegisterAndImmediateShift()
{
  int i;

  // Mov Register T3 and LSL Immediate T2
  for(i = 0b0000000; i < 0b0100000; i++)
  {
    if(i == 0b0)
      Thumb32MoveRegisterAndImmediateShift[i] = MOVRegisterT3;
    else
      Thumb32MoveRegisterAndImmediateShift[i] = LSLImmediateT2;
  }
  // LSR Immediate T2
  for(i = 0b0100000; i < 0b1000000; i++)
    Thumb32MoveRegisterAndImmediateShift[i] = LSRImmediateT2;
  // ASR Immediate T2
  for(i = 0b1000000; i < 0b1100000; i++)
    Thumb32MoveRegisterAndImmediateShift[i] = ASRImmediateT2;
  // RRX T1 and ROR Immediate T1
  for(i = 0b1100000; i < 0b10000000; i++)
  {
    if(i == 0b1100000)
      Thumb32MoveRegisterAndImmediateShift[i] = RRXT1;
    else
      Thumb32MoveRegisterAndImmediateShift[i] = RORImmediateT1;
  }
}


void initThumb32bitsDataProcessingRegister()
{
  Thumb32DataProcessingRegister[0b00000000] = LSLRegisterT2;
  Thumb32DataProcessingRegister[0b00010000] = LSLRegisterT2;
  Thumb32DataProcessingRegister[0b00100000] = LSRRegisterT2;
  Thumb32DataProcessingRegister[0b00110000] = LSRRegisterT2;
  Thumb32DataProcessingRegister[0b01000000] = ASRRegisterT2;
  Thumb32DataProcessingRegister[0b01010000] = ASRRegisterT2;
  Thumb32DataProcessingRegister[0b01100000] = RORRegisterT2;
  Thumb32DataProcessingRegister[0b01110000] = RORRegisterT2;
  Thumb32DataProcessingRegister[0b00001000] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001001] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001010] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001011] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001100] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001101] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001110] = SXTHT2;
  Thumb32DataProcessingRegister[0b00001111] = SXTHT2;
  Thumb32DataProcessingRegister[0b00011000] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011001] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011010] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011011] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011100] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011101] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011110] = UXTHT2;
  Thumb32DataProcessingRegister[0b00011111] = UXTHT2;
  Thumb32DataProcessingRegister[0b01001000] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001001] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001010] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001011] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001100] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001101] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001110] = SXTBT2;
  Thumb32DataProcessingRegister[0b01001111] = SXTBT2;
  Thumb32DataProcessingRegister[0b01011000] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011001] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011010] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011011] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011100] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011101] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011110] = UXTBT2;
  Thumb32DataProcessingRegister[0b01011111] = UXTBT2;
  // Miscellaneous operations
  Thumb32DataProcessingRegister[0b10011000] = REVT2;
  Thumb32DataProcessingRegister[0b10011001] = REV16T2;
  Thumb32DataProcessingRegister[0b10011010] = RBITT1;
  Thumb32DataProcessingRegister[0b10011011] = REVSHT2;
  Thumb32DataProcessingRegister[0b10111000] = CLZT1;
}


void initThumb32bitsDataProcessingPlainImmediate()
{
  // ADD Immediate T4 and ADR T3
  int i;

  for(i = 0b000000000; i < 0b000010000; i++)
  {
      if((i & 0b000001111) != 0b1111)
      {
        if((i & 0b000001101) != 0b1101)
          Thumb32DataProcessingPlainImmediate[i] = ADDImmediateT4;
        else
          Thumb32DataProcessingPlainImmediate[i] = ADDSPImmediateT4;
      }
      else
        Thumb32DataProcessingPlainImmediate[i] = ADRT3;
  }
  // MOV Immediate T3
  for(i = 0b001000000; i < 0b001010000; i++)
    Thumb32DataProcessingPlainImmediate[i] = MOVImmediateT3;
  // SUB Immediate T4 and ADR T2
  for(i = 0b010100000; i < 0b010110000; i++)
  {
      if((i & 0b000001111) != 0b1111)
      {
        if((i & 0b000001101) != 0b1101)
          Thumb32DataProcessingPlainImmediate[i] = SUBImmediateT4;
        else
          Thumb32DataProcessingPlainImmediate[i] = SUBSPImmediateT3;
      }
      else
        Thumb32DataProcessingPlainImmediate[i] = ADRT2;
  }
  // MOVT T1
  for(i = 0b011000000; i < 0b011010000; i++)
    Thumb32DataProcessingPlainImmediate[i] = MOVTT1;
  // SSAT T1
  for(i = 0b100000000; i < 0b100010000; i++)
    Thumb32DataProcessingPlainImmediate[i] = SSATT1;
  for(i = 0b100100000; i < 0b100110000; i++)
    Thumb32DataProcessingPlainImmediate[i] = SSATT1;
  // SBFX T1
  for(i = 0b101000000; i < 0b101010000; i++)
    Thumb32DataProcessingPlainImmediate[i] = SBFXT1;
  // BFI and BFC T1
  for(i = 0b101100000; i < 0b101110000; i++)
  {
      if((i & 0b000001111) != 0b1111)
        Thumb32DataProcessingPlainImmediate[i] = BFIT1;
      else
        Thumb32DataProcessingPlainImmediate[i] = BFCT1;
  }
  // USAT T1
  for(i = 0b110000000; i < 0b110010000; i++)
    Thumb32DataProcessingPlainImmediate[i] = USATT1;
  for(i = 0b110100000; i < 0b110110000; i++)
    Thumb32DataProcessingPlainImmediate[i] = USATT1;
  // UBFX T1
  for(i = 0b111000000; i < 0b111010000; i++)
    Thumb32DataProcessingPlainImmediate[i] = UBFXT1;
}


void initThumb32bitsDataProcessingModifiedImmediate()
{
  // AND and TST Immediate T1
  int i;

  for(i = 0b0000000000000; i < 0b0001000000000; i++)
  {
      if((i & 0b0000000001111) != 0b1111)
          Thumb32DataProcessingModifiedImmediate[i] = ANDImmediateT1;
      else
      {
          if(i >= 0b0000100000000)      // S == 1 and Rd == 1111
              Thumb32DataProcessingModifiedImmediate[i] = TSTImmediateT1;
      }
  }
  // BIC Immediate T1
  for(i = 0b0001000000000; i < 0b0010000000000; i++)
    Thumb32DataProcessingModifiedImmediate[i] = BICImmediateT1;
  // ORR Immediate T1 and MOV Immediate T2
  for(i = 0b0010000000000; i < 0b0011000000000; i++)
  {
      if((i & 0b0000011110000) != 0b11110000)
          Thumb32DataProcessingModifiedImmediate[i] = ORRImmediateT1;
      else
          Thumb32DataProcessingModifiedImmediate[i] = MOVImmediateT2;
  }
  // ORN and MVN Immediate T1
  for(i = 0b0011000000000; i < 0b0100000000000; i++)
  {
      if((i & 0b0000011110000) != 0b11110000)
          Thumb32DataProcessingModifiedImmediate[i] = ORNImmediateT1;
      else
          Thumb32DataProcessingModifiedImmediate[i] = MVNImmediateT1;
  }
  // EOR and TEQ Immediate T1
  for(i = 0b0100000000000; i < 0b0101000000000; i++)
  {
      if((i & 0b0000000001111) != 0b1111)
          Thumb32DataProcessingModifiedImmediate[i] = EORImmediateT1;
      else
      {
          if(i >= 0b0100100000000)      // S == 1 and Rd == 1111
            Thumb32DataProcessingModifiedImmediate[i] = TEQImmediateT1;
      }
  }
  // ADD Immediate T3 and CMN Immediate T1
  for(i = 0b1000000000000; i < 0b1001000000000; i++)
  {
      if((i & 0b0000000001111) != 0b1111)
      {
          if((i & 0b0000011010000) != 0b11010000)    // Rd != 1111 and Rn != 1101
            Thumb32DataProcessingModifiedImmediate[i] = ADDImmediateT3;
          else
            Thumb32DataProcessingModifiedImmediate[i] = ADDSPImmediateT3;
      }
      else
      {
          if(i >= 0b1000100000000)      // S == 1 and Rd == 1111
            Thumb32DataProcessingModifiedImmediate[i] = CMNImmediateT1;
      }
  }
  // ADC Immediate T1
  for(i = 0b1010000000000; i < 0b1011000000000; i++)
    Thumb32DataProcessingModifiedImmediate[i] = ADCImmediateT1;
  // SBC Immediate T1
  for(i = 0b1011000000000; i < 0b1110000000000; i++)
    Thumb32DataProcessingModifiedImmediate[i] = SBCImmediateT1;
  // SUB Immediate T3 and CMP Immediate T1
  for(i = 0b1101000000000; i < 0b1110000000000; i++)
  {
      if((i & 0b0000000001111) != 0b1111)
      {
          if((i & 0b0000011010000) != 0b11010000)    // Rd != 1111 and Rn != 1101
            Thumb32DataProcessingModifiedImmediate[i] = SUBImmediateT3;
          else
            Thumb32DataProcessingModifiedImmediate[i] = SUBSPImmediateT2;
      }
      else
      {
          if(i >= 0b1101100000000)      // S == 1 and Rd == 1111
            Thumb32DataProcessingModifiedImmediate[i] = CMPImmediateT2;
      }
  }
  // RSB Immediate T2
  for(i = 0b1110000000000; i < 0b1111000000000; i++)
    Thumb32DataProcessingModifiedImmediate[i] = RSBImmediateT2;
}



void initThumb32bitsBranchesAndMiscellaneousControl()
{
  int i;

  // Conditional Branch T2
  for(i = 0b0000000000; i < 0b0110000000; i++)
  {
    if((i & 0b111000) != 0b111000)
      Thumb32BranchesAndMiscellaneousControl[i] = ConditionalBranchT2;
  }
  // Unconditional Branch T2
  for(i = 0b0010000000; i < 0b1000000000; i++)
  {
    if((i & 0b10000000) == 0b10000000)
      Thumb32BranchesAndMiscellaneousControl[i] = UnconditionalBranchT2;
  }
  // BL T1
  for(i = 0b1010000000; i < 0b10000000000; i++)
  {
    if(((i & 0b1010000000) == 0b1010000000) || ((i & 0b1110000000) == 0b1110000000))
      Thumb32BranchesAndMiscellaneousControl[i] = BLT1;
  }
  // Hint Instructions
  Thumb32BranchesAndMiscellaneousControl[0b0000111010] = executeHintInstructions;
  Thumb32BranchesAndMiscellaneousControl[0b0100111010] = executeHintInstructions;
}


void initThumb32bitsHintInstructions()
{
  // NOP T2
  Thumb32HintInstructions[0] = NOPT2;
  //
}


void initThumb32bitsLoadWord()
{
  int i,j,k;
  uint32_t dummy;

  //LDRLiteral T2
  dummy = 0b000000001111;
  for(i = 0b0000000; i <= 0b1111111; i++)
  {
    dummy = setBits(dummy,i,10,4);
    Thumb32LoadWord[dummy] = LDRLiteralT2;
  }

  //LDRImmediate T3
  for(k = 0b000000; k <= 0b111111; k++)
  {
    dummy = setBits(dummy,k,9,4);
    for(j = 0; j < 0b1111; j ++)
    {
      dummy = setBits(dummy,j,3,0);
      Thumb32LoadWord[dummy] = LDRImmediateT3;
    }
  }


  //LDRImmediate T4
  dummy = 0b001001000000;
  for(k = 0; k < 4; k++)
  {
    dummy = setBits(dummy,k,8,7);
    for(i = 0; i < 4; i ++)
    {
      dummy = setBits(dummy, i, 5, 4);
      for(j = 0; j < 0b1111; j ++)
      {
        dummy = setBits(dummy,j,3,0);
        Thumb32LoadWord[dummy] = LDRImmediateT4;
      }
    }
  }

  dummy = 0b001100000000;
  for(i = 0; i < 4; i ++)
  {
    dummy = setBits(dummy, i, 5, 4);
    for(j = 0; j < 0b1111; j ++)
    {
      dummy = setBits(dummy,j,3,0);
      Thumb32LoadWord[dummy] = LDRImmediateT4;
    }
  }

  //LDR Register T2
  dummy = 0b000000000000;
  for(j = 0; j < 0b1111; j ++)
  {
    dummy = setBits(dummy,j,3,0);
    Thumb32LoadWord[dummy] = LDRRegisterT2;
  }

  //LDRT T1
  dummy = 0b001110000000;
  for(i = 0; i < 4; i ++)
  {
    dummy = setBits(dummy, i, 5, 4);
    for(j = 0; j < 0b1111; j ++)
    {
      dummy = setBits(dummy,j,3,0);
      Thumb32LoadWord[dummy] = LDRTT1;
    }
  }

}


void initThumb32bitsMultiplyAccumulate()
{
  int i,j,k;
  uint32_t dummy;

  //MLA T1
  dummy = 0b000000000;
  for(j = 0; j < 0b1111; j ++)
  {
    dummy = setBits(dummy,j,3,0);
    Thumb32MultiplyAccumulate[dummy] = MLAT1;
  }

  //MUL T2
  Thumb32MultiplyAccumulate[0b000001111] = MULRegisterT2;

  //MLS
  dummy = 0b000010000;
  for(j = 0; j <= 0b1111; j ++)
  {
    dummy = setBits(dummy,j,3,0);
    Thumb32MultiplyAccumulate[dummy] = MLST1;
  }
}



void initThumb32bitsLongMultiplyAccumulateDivide()
{
  Thumb32LongMultiplyAccumulateDivide[0b0000000] = SMULLT1;
  Thumb32LongMultiplyAccumulateDivide[0b0011111] = SDIVT1;
  Thumb32LongMultiplyAccumulateDivide[0b0100000] = UMULLT1;
  Thumb32LongMultiplyAccumulateDivide[0b0111111] = UDIVT1;
  Thumb32LongMultiplyAccumulateDivide[0b1000000] = SMLALT1;
  Thumb32LongMultiplyAccumulateDivide[0b1100000] = UMLALT1;

}




void initThumb32bitsLoadStoreMultiple()
{
  uint32_t dummy;
  int i,j,k;

  //STM Register T2
  dummy = 0b01000000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32LoadStoreMultiple[dummy] = STMRegisterT2;
  }

  //LDM Register T2
  dummy = 0b01100000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    if(dummy != 0b01111101)
      Thumb32LoadStoreMultiple[dummy] = LDMRegisterT2;
  }

  //STMDB
  dummy = 0b10000000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    if(dummy != 0b10011101)
      Thumb32LoadStoreMultiple[dummy] = STMDB;
  }

  //LDMDB
  dummy = 0b10100000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32LoadStoreMultiple[dummy] = LDMDB;
  }

  //POP T2
  Thumb32LoadStoreMultiple[0b01111101] = POPT2;

  //PUSH T2
  Thumb32LoadStoreMultiple[0b10011101] = PUSHT2;
}



void initThumb32StoreSingleDataItem()
{
  uint32_t dummy;
  int i,j,k;

  //STRB(immediate)
  dummy = 0b100000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,5,0);
    Thumb32StoreSingleDataItem[dummy] = STRBImmediateT2;
  } 
  
  dummy = 0b000100000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32StoreSingleDataItem[dummy] = STRBImmediateT3;
  } 
  //
  dummy = 0b000000000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32StoreSingleDataItem[dummy] = STRBRegisterT2;
  }
  //
  dummy = 0b101000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,5,0);
    Thumb32StoreSingleDataItem[dummy] = STRHImmediateT2;
  }
  
  dummy = 0b001100000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32StoreSingleDataItem[dummy] = STRHImmediateT3;
  }
  //
  dummy = 0b001000000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32StoreSingleDataItem[dummy] = STRHRegisterT2;
  }
  //
  dummy = 0b010000000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32StoreSingleDataItem[dummy] = STRRegisterT2;
  }
  //
  dummy = 0b110000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,5,0);
    Thumb32StoreSingleDataItem[dummy] = STRImmediateT3;
  }
  
  dummy = 0b010100000;
  for(j = 0; j <= 0b11111; j ++)
  {
    dummy = setBits(dummy,j,4,0);
    Thumb32StoreSingleDataItem[dummy] = STRImmediateT4;
  }
  
}


void initThumb32LoadByteMemoryHints()
{
  uint32_t dummy;
  int i,j,k,h;
  
  //
  dummy = 0b0100000000000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,13,8);
    for(i = 0; i < 0b1111; i++)
    {
      dummy = setBits(dummy,i,7,4);
      for(k = 0; k < 0b1111; k++)
      {
        dummy = setBits(dummy,k,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRBImmediateT2;
      }
    }
  }
  
  dummy = 0b0010010000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,12,11);
    for(i = 0; i <= 0b11; i++)
    {
      dummy = setBits(dummy,i,9,8);
      for(k = 0; k < 0b1111; k++)
      {
        dummy = setBits(dummy,k,7,4);
        for(h = 0; h <= 0b1111; h++)
        {
          dummy = setBits(dummy,h,3,0);
          Thumb32LoadByteMemoryHints[dummy] = LDRBImmediateT3;
        }
      }
    }
  }
  
  dummy = 0b0011000000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,9,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRBImmediateT3;
      }
    }
  }
  //
  dummy = 0b0011100000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,9,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRBT;
      }
    }
  }
  //
  dummy = 0b0000000011110000;
  for(k = 0; k <= 0b1111111; k++)
  {
    dummy = setBits(dummy,k,14,8);
    for(h = 0; h < 0b1111; h++)
    {
      dummy = setBits(dummy,h,3,0);
      Thumb32LoadByteMemoryHints[dummy] = LDRBLiteral;
    }
  }
  //LDRBRegisterT2
  dummy = 0b0000000000000000;
  for(k = 0; k < 0b1111; k++)
  {
    dummy = setBits(dummy,k,7,4);
    for(h = 0; h < 0b1111; h++)
    {
      dummy = setBits(dummy,h,3,0);
      Thumb32LoadByteMemoryHints[dummy] = LDRBRegisterT2;
    }
  }
  //
  dummy = 0b1100000000000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,13,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRSBImmediateT1;
      }
    }
  }
  
  dummy = 0b1010010000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,12,11);
    for(k = 0; k <= 0b11; k++)
    {
      dummy = setBits(dummy,k,9,8);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,7,4);
        for(i = 0; i <= 0b1111; i++)
        {
          dummy = setBits(dummy,i,3,0);
          Thumb32LoadByteMemoryHints[dummy] = LDRSBImmediateT2;
        }
      }
    }
  }
  
  dummy = 0b1011000000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,9,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRSBImmediateT2;
      }
    }
  }
  //
  dummy = 0b1011100000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,9,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h <= 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRSBT;
      }
    }
  }
  //
  dummy = 0b1011100000000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,9,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h <= 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadByteMemoryHints[dummy] = LDRSBT;
      }
    }
  }
  //
  dummy = 0b1000000011110000;
  for(j = 0; j <= 0b1111111; j ++)
  {
    dummy = setBits(dummy,j,14,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,3,0);
      Thumb32LoadByteMemoryHints[dummy] = LDRSBLiteral;
    }
  }
  //
  dummy = 0b1000000000000000;
  for(j = 0; j < 0b1111; j ++)
  {
    dummy = setBits(dummy,j,7,4);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,3,0);
      Thumb32LoadByteMemoryHints[dummy] = LDRSBRegisterT2;
    }
  }

}


void initThumb32bitsLoadStoreDualTableBranch()
{
  uint32_t dummy;
  int i,j,k,h;
  
  
  dummy = 0b00000000;
  for(k = 0; k <= 0b1111; k++)
  {
    dummy = setBits(dummy,k,3,0);
    Thumb32LoadStoreDualTableBranch[dummy] = STREX;
  }
  //
  dummy = 0b00100000;
  for(j = 0; j < 2; j ++)
  {
    dummy = setBits(dummy,j,6,6);
    for(k = 0; k <= 0b1111; k++)
    {
      dummy = setBits(dummy,k,3,0);
      Thumb32LoadStoreDualTableBranch[dummy] = STRDImmediate;
    }
  }
  //
  dummy = 0b10000000;
  for(j = 0; j <= 0b11; j ++)
  {
    dummy = setBits(dummy,j,6,5);
    for(k = 0; k <= 0b1111; k++)
    {
      dummy = setBits(dummy,k,3,0);
      Thumb32LoadStoreDualTableBranch[dummy] = STRDImmediate;
    }
  }
  //
  dummy = 0b00110000;
  for(j = 0; j < 2; j ++)
  {
    dummy = setBits(dummy,j,6,6);
    for(k = 0; k <= 0b1111; k++)
    {
      dummy = setBits(dummy,k,3,0);
      Thumb32LoadStoreDualTableBranch[dummy] = LDRDImmediate;
    }
  }
  //
  dummy = 0b10010000;
  for(j = 0; j < 4; j ++)
  {
    dummy = setBits(dummy,j,6,5);
    for(k = 0; k <= 0b1111; k++)
    {
      dummy = setBits(dummy,k,3,0);
      Thumb32LoadStoreDualTableBranch[dummy] = LDRDImmediate;
    }
  }
}




void initThumb32bitsLoadHalfword()
{
  uint32_t dummy;
  int i,j,k,h;
  //
  dummy = 0b0100000000000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,13,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);        
        Thumb32LoadHalfword[dummy] = LDRHImmediateT2;
      }
    }
  }
  /*
  dummy = 0b0010010000000000;
  for(i = 0; i <= 0b11; i ++)
  {
    dummy = setBits(dummy,i,12,11);
    for(j = 0; j <= 0b11; j ++)
    {
      dummy = setBits(dummy,j,9,8);
      for(k = 0; k < 0b1111; k++)
      {
        dummy = setBits(dummy,k,7,4);
        for(h = 0; h < 0b1111; h++)
        {
          dummy = setBits(dummy,h,3,0);
          Thumb32LoadHalfword[dummy] = LDRHImmediateT3;
        }
      }
    }
  }
  
  dummy = 0b0100000000000000;
  for(j = 0; j <= 0b111111; j ++)
  {
    dummy = setBits(dummy,j,13,8);
    for(k = 0; k < 0b1111; k++)
    {
      dummy = setBits(dummy,k,7,4);
      for(h = 0; h < 0b1111; h++)
      {
        dummy = setBits(dummy,h,3,0);
        Thumb32LoadHalfword[dummy] = LDRHImmediateT3;
      }
    }
  }
  //
  */
}
















