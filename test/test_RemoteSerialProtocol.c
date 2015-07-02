#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "unity.h"
#include "ARMRegisters.h"
// #include "StatusRegisters.h"
// #include "getBits.h"
// #include "getMask.h"
#include "RemoteSerialProtocol.h"
#include "mock_Packet.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*
 * qL<startflag><thread count><next thread> -- obtain thread info
 *
 * startflag (one hex digit) is one to indicate the first query
 * and zero to indicate a subsequent query
 *
 * thread count (two hex digits) is the maximum number of threads
 * the response packet can contain
 *
 * next thread (eight hex digits), for subsequent queries (startflag is zero),
 * is returned in the response as argthread
 */
void test_handleQueryPacket_given_data_with_qL_should_return_empty_response(void)
{
    char data[] = "$qL1160000000000000000#55";
    char *reply;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

/*
 * qC -- current thread
 *
 * Reply:
 *      QCpid       Where pid is a HEX encoded 16 bit process id
 *      *           Any other reply implies the old pid
 *
 */
void test_handleQueryPacket_given_data_with_qC_should_return_empty_response(void)
{
    char data[] = "$qC#b4";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

/*
 * qCRC:addr,length -- Compute the CRC checksum of a block of memory
 *
 * Reply:
 *      E NN        An error (such as memory fault)
 *      C crc32     The specified memory region's checksum is crc32
 *
 */
void test_handleQueryPacket_given_data_with_qCRC_should_return_E01_response(void)
{
    char data[] = "$qCRC#49";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("E01", "$E01#a6");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$E01#a6", reply);
}

void test_handleQueryPacket_given_qSupported_should_return_appropriate_response(void)
{
    char data[] = "$qSupported:multiprocess+;qRelocInsn+#2a";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("qRelocInsn-", "$qRelocInsn-#2b");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$qRelocInsn-#2b", reply);
}

/*
 * qAttached:pid -- Indication of whether the remote server attached to an
 *                  existing process or created a new process
 *
 * Reply:
 *      1       The remote server attached to an existing process
 *      0       The remote server created a new process
 *      E NN    An error occurred, nn are hex digits
 */
void test_handleQueryPacket_given_data_with_qAttached_should_return_empty_response(void)
{
    char data[] = "$qAttached#8f";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

/*
 * qTStatus -- Ask the stub if there is a trace experiment running right now
 *
 * Reply:
 *      T0       There is no trace experiment running
 *      T1       There is a trace experiment running
 */
void test_handleQueryPacket_given_data_with_qTStatus_should_return_empty_response(void)
{
    char data[] = "$qTStatus#49";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

/*
 * qfThreadInfo -- Ask the stub if there is a trace experiment running right now
 *
 * Reply:
 *      T0       There is no trace experiment running
 *      T1       There is a trace experiment running
 */
void test_handleQueryPacket_given_data_with_qfThreadInfo_should_return_empty_response(void)
{
    char data[] = "$qfThreadInfo#bb";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

/*
 * qOffsets -- Get section offsets that the target used when relocating the downloaded image
 *
 * Reply:
 *      Text=xxx;Data=yyy[;Bss=zzz]
 *      TextSeg=xxx[;DataSeg=yyy]
 */
void test_handleQueryPacket_given_data_with_qOffsets_should_return_empty_response(void)
{
    char data[] = "$qOffsets#4b";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

/*
 * qSymbol:: -- Notify the target that No value for GDBN is prepared to serve symbol lookup requests.
 *              Accept requests from the target for the values of symbols
 *
 * Reply:
 *      OK                  The target does not need to look up any (more) symbols
 *      qSymbol:sym_name
 */
void test_handleQueryPacket_given_data_with_qSymbol_should_return_empty_response(void)
{
    char data[] = "$qSymbol::#5b";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

void test_handleQueryPacket_given_data_with_unrecognized_RSP_query_should_return_empty_response(void)
{
    char data[] = "$qB#b3";
    char *reply = NULL;

    gdbCreateMsgPacket_ExpectAndReturn("", "$#00");

    reply = handleQueryPacket(data);

    TEST_ASSERT_EQUAL_STRING("$#00", reply);
}

void test_readSingleRegister_given_data_with_p10_packet_should_return_appropriate_response(void)
{
    char data[] = "$p10#d1";
    char *reply = NULL;
    initCoreRegister();

    createdHexToString_ExpectAndReturn(0x01000000, "01000000");
    gdbCreateMsgPacket_ExpectAndReturn("01000000", "$01000000#81");
    destroyHexToString_Expect("01000000");

    reply = readSingleRegister(data);

    TEST_ASSERT_EQUAL_STRING("$01000000#81", reply);
}

void test_readAllRegister_should_return_appropriate_response_with_all_reg_val(void)
{
    char *reply = NULL;
    int i;
    initCoreRegister();

    for(i = 0; i < 17; i++)
    {
        if(i < 16)
        {
            createdHexToString_ExpectAndReturn(0x00000000, "00000000");
            destroyHexToString_Expect("00000000");
        }
        else
        {
            createdHexToString_ExpectAndReturn(0x01000000, "01000000");
            destroyHexToString_Expect("01000000");
        }
    }

    gdbCreateMsgPacket_ExpectAndReturn("0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000",  \
                                       "$0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000#81");

    reply = readAllRegister();

    TEST_ASSERT_EQUAL_STRING("$0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000#81", reply);
}

void test_writeSingleRegister_given_following_data_should_write_value_to_a_register(void)
{
    char data[] = "$P6=1052ffff#23";
    initCoreRegister();

    writeSingleRegister(data);

    TEST_ASSERT_EQUAL(0x1052ffff, coreReg[6]);
}

void test_writeAllRegister_given_following_data_should_write_value_to_all_register(void)
{
    char data[] = "$G00000000111111112222222233333333444444445555555566666666777777778888888899999999aaaaaaaabbbbbbbbccccccccddddddddeeeeeeeeffffffff01000000#c8";
    initCoreRegister();

    writeAllRegister(data);

    TEST_ASSERT_EQUAL(0x00000000, coreReg[0]);
    TEST_ASSERT_EQUAL(0x11111111, coreReg[1]);
    TEST_ASSERT_EQUAL(0x22222222, coreReg[2]);
    TEST_ASSERT_EQUAL(0x33333333, coreReg[3]);
    TEST_ASSERT_EQUAL(0x44444444, coreReg[4]);
    TEST_ASSERT_EQUAL(0x55555555, coreReg[5]);
    TEST_ASSERT_EQUAL(0x66666666, coreReg[6]);
    TEST_ASSERT_EQUAL(0x77777777, coreReg[7]);
    TEST_ASSERT_EQUAL(0x88888888, coreReg[8]);
    TEST_ASSERT_EQUAL(0x99999999, coreReg[9]);
    TEST_ASSERT_EQUAL(0xaaaaaaaa, coreReg[10]);
    TEST_ASSERT_EQUAL(0xbbbbbbbb, coreReg[11]);
    TEST_ASSERT_EQUAL(0xcccccccc, coreReg[12]);
    TEST_ASSERT_EQUAL(0xdddddddd, coreReg[SP]);
    TEST_ASSERT_EQUAL(0xeeeeeeee, coreReg[LR]);
    TEST_ASSERT_EQUAL(0xffffffff, coreReg[PC]);
    TEST_ASSERT_EQUAL(0x01000000, coreReg[xPSR]);
}

void test_step_given_following_data_should_return_signal_value_pc_reg_value_and_r7_value(void)
{
    char data[] = "$s#73";
    char *reply = NULL;

    initCoreRegister();
    coreReg[PC] = 0x080d0008;
    coreReg[7] = 0x7cff0120;

    createdHexToString_ExpectAndReturn(0x080d0008, "080d0008");
    createdHexToString_ExpectAndReturn(0x7cff0120, "7cff0120");
    destroyHexToString_Expect("080d0008");
    destroyHexToString_Expect("7cff0120");
    gdbCreateMsgPacket_ExpectAndReturn("T050f:080d0008;07:7cff0120", "$T050f:080d0008;07:7cff0120#52");

    reply = step(data);

    TEST_ASSERT_EQUAL_STRING("$T050f:080d0008;07:7cff0120#52", reply);
}