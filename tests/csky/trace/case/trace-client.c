/*
 * Copyright (c) 2021 T-Head Semiconductor Co., Ltd. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#define INST_BASE 0x4
#define INST_OFFSET 0x5
#define INST_ASID 0x10
#define INST_EXCP 0x11
#define INST_TEE 0x12
#define DATA_RADDR 0x40
#define DATA_WADDR 0x41
#define DATA_VALUE 0x42

#define SYN 0x02
#define START 0
#define END 7
#define ICOUNT 1

#define SYN_START ((START << 8) | SYN)
#define SYN_END ((END << 8) | SYN)
#define SYN_ICOUNT ((ICOUNT << 8) | SYN)

#define OVERFLOW(pos, board)    do {                \
if (pos >= board) {                                 \
        memcpy(rest, &buf[start], plen - start);    \
        rlen = plen - start;                        \
        return;                                     \
    }                                               \
} while (0)

#define MAX_REST_LENGTH 512 

static char rest[MAX_REST_LENGTH] =  {0};
static int rlen = 0;
static char lbase = -1;

static int tb_num = 0;
static long long insn_num = 0;

static int raddr_num = 0;
static int waddr_num = 0;
static int rdata_num = 0;
static int wdata_num = 0;



void handle_packet(char *ibuf, int plen)
{
    int start = 0;
    int ulen = 0;
    int data_len = 0;

    char *buf = (char *)malloc(plen + rlen);
    if (rlen > 0) {
        memcpy(buf, rest, rlen);
    }
    memcpy(buf + rlen, ibuf, plen);
    memset(rest, 0, MAX_REST_LENGTH);
    plen += rlen;
    rlen = 0;
    for (int i = 0; i < plen; i++) {
        start = i;
        switch (buf[i]) {
        case SYN:
            ulen = i + 9;
            OVERFLOW(ulen , plen);
            i++;
            if (buf[i] == START) {
                i++;
                if (buf[i] == SYN) {
                    i++;
                    if (buf[i] == ICOUNT) {
                        i++;
                        insn_num += *(int *)&buf[i];
                        i += 4;
                        if (buf[i] == SYN) {
                            i++;
                            if (buf[i] == END) {
                                break;
                            } else {
                                printf("1 encount an error in parse SYN\n");
                                return;
                            }
                        } else {
                            printf("2 encount an error in parse SYN\n");
                            return;
                        }
                    } else {
                        printf("3 encount an error in parse SYN\n");
                        return;
                    }
                } else {
                    printf("4 encount an error in parse SYN\n");
                    return;
                }
            } else {
                printf("5 encount an error in parse SYN\n");
                return;
            }
            break;
        case INST_BASE:
            ulen = i + 1;
            OVERFLOW(ulen, plen);
            i++;
            lbase = buf[i];
            break;
        case INST_OFFSET:
            ulen = i + 3;
            OVERFLOW(ulen, plen);
            i++;
            tb_num++;
            i += 2;
            break;
        case DATA_RADDR:
            ulen = i + 5;
            OVERFLOW(ulen, plen);
            i++;
            data_len = buf[i];
            if (data_len <= 4) {
                data_len = 6;
            } else {
                data_len = (data_len / 4) * 6;
            }
            i++;
            i += 4;
            ulen = i + data_len - 1;
            OVERFLOW(ulen, plen);
            raddr_num++;
            rdata_num += buf[start + 1];
            i = ulen; 
            break;
        case DATA_WADDR:
            ulen = i + 5;
            OVERFLOW(ulen, plen);
            i++;
            data_len = buf[i];
            if (data_len <= 4) {
                data_len = 6;
            } else {
                data_len = (data_len / 4) * 6;
            }
            i++;
            i += 4;
            ulen = i + data_len - 1;
            OVERFLOW(ulen, plen);
            waddr_num++;
            wdata_num += buf[start + 1];
            i = ulen;
            break;
        default:
            break;
        }
    }

}
int  main(int port)
{
    struct sockaddr_in server;
    int connectfd;
    char *buf = (char *)malloc(16 * 1024 * 1024);
    memset(buf, 0, 16 * 1024 * 1024);
    int fd;
    fd = open("cpf.data", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    in_addr_t ip_addr = inet_addr("127.0.0.1");
    if ((connectfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        exit(-1);
    }
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8810);
    server.sin_addr = *(struct in_addr *)&ip_addr;

    if (connect(connectfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("connect error %s\n", strerror(errno));
        exit(-2);
    }
    printf("******************************\n");
    printf("----------START TRACE---------\n");
    int i = 0, len = 0, count = 0;
    while (1) {
        if ((len = recv(connectfd, buf, 16 * 1024 * 1024, 0)) > 0) {
            handle_packet(buf, len);
        } else {
            printf("TB NUM   : %d\n", tb_num);
            printf("INSN NUM : %lld\n", insn_num);
            printf("RADDR NUM: %d\n", raddr_num);
            printf("WADDR NUM: %d\n", waddr_num);
            printf("RDATA NUM: %d\n", rdata_num);
            printf("WDATA NUM: %d\n", wdata_num);
            printf("-----------END TRACE----------\n");
            printf("******************************\n");
            return 0;
        }
        //for(; i < len; i += 4){
        //    printf("%x\t", *(unsigned int*)&buf[i]);
        //}
        write(fd, buf, len);
        count += len;
        //printf("recv count %x\n", count);
        i = 0;
        len = 0;
        memset(buf, 0, 16 * 1024 * 1024);
    }
    return 0;
}
