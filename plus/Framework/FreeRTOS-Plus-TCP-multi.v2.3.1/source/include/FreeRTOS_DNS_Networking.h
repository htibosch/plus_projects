/*
 * FreeRTOS+TCP V2.3.2
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://github.com/FreeRTOS
 * https://www.FreeRTOS.org
 */
#ifndef FREERTOS_DNS_NETWORKING_H
#define FREERTOS_DNS_NETWORKING_H

#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_DNS_Globals.h"

#if ( ipconfigUSE_DNS != 0 )

/*
 * Create a socket and bind it to the standard DNS port number.  Return the
 * the created socket - or NULL if the socket could not be created or bound.
 */
    Socket_t DNS_CreateSocket( TickType_t uxReadTimeOut_ticks );

    BaseType_t DNS_BindSocket( Socket_t xSocket,
                               uint16_t usPort );

    uint32_t DNS_SendRequest( Socket_t xDNSSocket,
                              struct freertos_sockaddr * xAddress,
                              uint8_t * pucBuffer,
                              size_t uxBufferLength );

    int32_t DNS_ReadReply( Socket_t xDNSSocket,
                           struct freertos_sockaddr * xAddress,
                           uint8_t ** ppucReceiveBuffer );

    void DNS_CloseSocket( Socket_t xDNSSocket );
#endif /* if ( ipconfigUSE_DNS != 0 ) */
#endif /* ifndef FREERTOS_DNS_NETWORKING_H */
