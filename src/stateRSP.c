#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "stateRSP.h"
#include "ServeRSP.h"
#include "Packet.h"

/***********************************************************************
 * State machine to handle communication between gdb client and server.
 *
 * Input:
 *      rspData     pointer to RspData data structure
 *
 * Return:
 *      packet      string of data reply to gdb
 ***********************************************************************/
// char *rspState(RspData *rspData, char *data)
void rspState(RspData *rspData, char *data)
{
    // char *packet = NULL;
    static int nack = 0;

    if(data[0] == '+')
    {
        switch(data[1])
        {
            case '\0':
                sendBuffer(&(rspData->sock), "+");
                rspData->state = ACK;
                break;
            case '$':
                data++;
                // printf("data: %s\n", data);

                if(!verifyPacket(data))
                {
                    // printf("yes\n");
                    sendBuffer(&(rspData->sock), "-");
                    rspData->state = NACK;
                }
                else
                {
                    sendBuffer(&(rspData->sock), "+");
                    rspData->state = SERVE_RSP;
                }
                break;
            default:
                sendBuffer(&(rspData->sock), "-");
                rspData->state = NACK;
                break;
        }
    }
    else if(data[0] == '-')
    {
        sendBuffer(&(rspData->sock), "-");
        rspData->state = NACK;
    }

again:
    switch(rspData->state)
    {
        case INITIAL:
            if(data[0] == '+')
            {
                rspData->state = ACK;
            }
            else if(data[0] == '-')
            {
                rspData->state = NACK;
            }

            break;
        case ACK:
            nack = 0;
            rspData->state = SERVE_RSP;
            // printf("yes\n");
            break;
        case NACK:
            nack++;
            // printf("nack: %d\n", nack);

            if(nack == 5)
                rspData->state = KILL;
            else
                rspData->state = INITIAL;
            break;
        case SERVE_RSP:
            /* if(!verifyPacket(data))
            {
                printf("yes\n");
                sendBuffer(&(rspData->sock), "-");
                rspData->state = NACK;
            } */
            // else
            // {
                if(!strcmp("$k#6b", data))
                {
                    rspData->state = KILL;
                    break;
                }
                sendBuffer(&(rspData->sock), serveRSP(data));
                // packet = serveRSP(data);
                // printf("yes\n");
            // }

            rspData->state = INITIAL;
            break;
        case KILL:
            rspData->state = INITIAL;
            break;
        default:
            rspData->state= INITIAL;
            break;
    }

    if(rspData->state == NACK)
        goto again;
    // return packet;
}
