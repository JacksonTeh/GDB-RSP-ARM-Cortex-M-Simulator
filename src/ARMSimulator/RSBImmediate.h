#ifndef RSBImmediate_H
#define RSBImmediate_H

#include "ARMRegisters.h"
#include "getAndSetBits.h"
#include "StatusRegisters.h"
#include <stdint.h>
#include "ModifiedImmediateConstant.h"

void RSBImmediateT1(uint32_t instruction);
void RSBImmediateT2(uint32_t instruction);
void executeRSBImmediate(uint32_t immediate, uint32_t Rn, uint32_t Rd, uint32_t S);

#endif // RSBImmediate_H
