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

#include <testsuite.h>
#include <test_device.h>
volatile int i;
int core0()
{
    init_testsuite("Test CK860 boot\n");
    printf("cpu0_running\n");
    i++;
    return 0;
}
int core1()
{
    printf("cpu1_running\n");
    i++;
    return 0;
}
int core2()
{
    printf("cpu2_running\n");
    i++;
    return 0;
}
int core3()
{
    printf("cpu3_running\n");
    TEST(i == 3);
    return done_testing();
}
