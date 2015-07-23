#include <string.h>
#include <malloc.h>
#include "unity.h"
#include "stateRSP.h"
#include "ServeRSP.h"
#include "Packet.h"
#include "RemoteSerialProtocol.h"
#include "ARMRegisters.h"
#include "ROM.h"
#include "getAndSetBits.h"
#include "getMask.h"
#include "CException.h"
#include "ErrorSignal.h"
#include "ARMSimulator.h"
#include "ConditionalExecution.h"
#include "StatusRegisters.h"
#include "Thumb16bitsTable.h"
#include "LSLImmediate.h"
#include "LSRImmediate.h"
#include "MOVRegister.h"
#include "ASRImmediate.h"
#include "MOVImmediate.h"
#include "ModifiedImmediateConstant.h"
#include "CMPImmediate.h"
#include "ADDImmediate.h"
#include "SUBImmediate.h"
#include "ADDRegister.h"
#include "SUBRegister.h"
#include "ADDSPRegister.h"
#include "ITandHints.h"
#include "ANDRegister.h"
#include "LSLRegister.h"
#include "LSRRegister.h"
#include "ASRRegister.h"
#include "CMPRegister.h"
#include "CMNRegister.h"
#include "EORRegister.h"
#include "ORRRegister.h"
#include "RORRegister.h"
#include "MVNRegister.h"
#include "BICRegister.h"
#include "ADCRegister.h"
#include "BX.h"
#include "BLXRegister.h"
#include "MULRegister.h"
#include "TSTRegister.h"
#include "RSBImmediate.h"
#include "SBCRegister.h"
#include "UnconditionalAndConditionalBranch.h"
#include "STRRegister.h"
#include "State.h"
#include "LDRImmediate.h"
#include "LDRLiteral.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_rsp_state_given_ack_data_and_INITIAL_state_should_change_to_ACK_state(void)
{
    State state = INITIAL;
    char data[] = "+";
    char *packet = NULL;

    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING(NULL, packet);
    TEST_ASSERT_EQUAL(ACK, state);
}

void test_rsp_state_given_nack_data_and_INITIAL_state_should_change_to_NACK_state(void)
{
    State state = INITIAL;
    char data[] = "-";
    char *packet = NULL;

    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING(NULL, packet);
    TEST_ASSERT_EQUAL(NACK, state);

    free(packet);
}

void test_rsp_state_given_k_data_packet_and_INITIAL_state_should_change_to_KILL_state(void)
{
    State state = INITIAL;
    char data[] = "$k#6b";
    char *packet = NULL;

    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING(NULL, packet);
    TEST_ASSERT_EQUAL(KILL, state);

    free(packet);
}

void test_rsp_state_twice_given_ack_data_and_INITIAL_state_should_return_ack_packet(void)
{
    State state = INITIAL;
    char data[] = "+";
    char *packet = NULL;

    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING("+", packet);
    TEST_ASSERT_EQUAL(SERVE_RSP, state);

    free(packet);
}

void test_rsp_state_twice_given_nack_data_and_INITIAL_state_should_return_nack_packet(void)
{
    State state = INITIAL;
    char data[] = "-";
    char *packet = NULL;

    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING("-", packet);
    TEST_ASSERT_EQUAL(INITIAL, state);

    free(packet);
}

void test_rsp_state_given_NACK_state_should_change_to_KILL_state_if_nack_data_recveive_more_than_five_time(void)
{
    State state = ACK;      //to clear the nack
    char data[] = "-";
    char *packet = NULL;

    packet = rsp_state(&state, data);

    state = NACK;
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING("-", packet);
    TEST_ASSERT_EQUAL(KILL, state);

    free(packet);
}

void test_rsp_state_twice_given_k_data_packet_and_INITIAL_state_should_return_k_packet(void)
{
    State state = INITIAL;
    char data[] = "$k#6b";
    char *packet = NULL;

    packet = rsp_state(&state, data);
    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING("k", packet);
    TEST_ASSERT_EQUAL(INITIAL, state);

    free(packet);
}

void test_rsp_state_given_data_and_SERVE_RSP_state_should_return_appropriate_packet(void)
{
    State state = SERVE_RSP;
    char data[] = "$qSupported:multiprocess+;qRelocInsn+#2a";
    char *packet = NULL;

    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING("$PacketSize=3fff;qXfer:memory-map:read-;qXfer:features:read+;qRelocInsn-#58", packet);
    // TEST_ASSERT_EQUAL_STRING("$qXfer:memory-map:read-;qXfer:features:read+;qRelocInsn-#88", packet);
    TEST_ASSERT_EQUAL(INITIAL, state);

    free(packet);
}

void test_rsp_state_given_data_with_wrong_chksum_and_SERVE_RSP_state_should_return_nack_packet(void)
{
    State state = SERVE_RSP;
    char data[] = "$qSupported:multiprocess+;qRelocInsn+#4a";
    char *packet = NULL;

    packet = rsp_state(&state, data);

    TEST_ASSERT_EQUAL_STRING("-", packet);
    TEST_ASSERT_EQUAL(INITIAL, state);

    free(packet);
}

void test_rsp_state_given_data_and_INITIAL_state_should_return_appropriate_packet(void)
{
    State state = INITIAL;
    char data1[] = "+";
    char *packet = NULL;

    packet = rsp_state(&state, data1);
    TEST_ASSERT_EQUAL_STRING(NULL, packet);
    TEST_ASSERT_EQUAL(ACK, state);

    packet = rsp_state(&state, data1);
    TEST_ASSERT_EQUAL_STRING("+", packet);
    TEST_ASSERT_EQUAL(SERVE_RSP, state);
    free(packet);

    char data2[] = "$qSupported:multiprocess+;qRelocInsn+#2a";

    packet = rsp_state(&state, data2);
    TEST_ASSERT_EQUAL_STRING("$PacketSize=3fff;qXfer:memory-map:read-;qXfer:features:read+;qRelocInsn-#58", packet);
    TEST_ASSERT_EQUAL(INITIAL, state);
    free(packet);
}