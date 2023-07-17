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

   .file   "rvv_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_vmaqa_vv)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v2, (a1)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqa.vv  v8, v1, v2, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqa_vv, .-test_vmaqa_vv

TEST_FUNC(test_vmaqau_vv)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v2, (a1)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqau.vv  v8, v1, v2, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqau_vv, .-test_vmaqau_vv

TEST_FUNC(test_vmaqasu_vv)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v2, (a1)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqasu.vv  v8, v1, v2, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqasu_vv, .-test_vmaqasu_vv

TEST_FUNC(test_vpmaqa_vv)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v2, (a1)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqa.vv  v8, v1, v2, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqa_vv, .-test_vpmaqa_vv

TEST_FUNC(test_vpmaqau_vv)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v2, (a1)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqau.vv  v8, v1, v2, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqau_vv, .-test_vpmaqau_vv

TEST_FUNC(test_vpmaqasu_vv)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v2, (a1)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqasu.vv  v8, v1, v2, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqasu_vv, .-test_vpmaqasu_vv

TEST_FUNC(test_vmaqa_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqa.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqa_vx, .-test_vmaqa_vx

TEST_FUNC(test_vmaqau_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqau.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqau_vx, .-test_vmaqau_vx

TEST_FUNC(test_vmaqasu_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqasu.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqasu_vx, .-test_vmaqasu_vx

TEST_FUNC(test_vmaqaus_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vmaqaus.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vmaqaus_vx, .-test_vmaqaus_vx

TEST_FUNC(test_vpmaqa_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqa.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqa_vx, .-test_vpmaqa_vx

TEST_FUNC(test_vpmaqau_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqau.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqau_vx, .-test_vpmaqau_vx

TEST_FUNC(test_vpmaqasu_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqasu.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqasu_vx, .-test_vpmaqasu_vx

TEST_FUNC(test_vpmaqaus_vx)
    li        t0, 16 
    vsetvli   t0, t0, e8, m1, tu, mu
    vle8.v    v1, (a0)
    vle8.v    v0, (a3)
    srli      t0, t0, 2
    vsetvli   t0, t0, e32, m1, tu, mu
    vle32.v   v8, (a4)
    vpmaqaus.vx  v8, a1, v1, v0.t
    vse32.v   v8, (a2)
    ret
    .size   test_vpmaqaus_vx, .-test_vpmaqaus_vx

TEST_FUNC(test_vpnclip_wv)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v2, (a1)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v1, (a0)
    vle8.v     v0, (a3)
    vle8.v     v8, (a4)
    vpnclip.wv v8, v2, v1, v0.t
    vse8.v     v8, (a2)
    ret
    .size   test_vpnclip_wv, .-test_vpnclip_wv

TEST_FUNC(test_vpnclipu_wv)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v2, (a1)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v1, (a0)
    vle8.v     v0, (a3)
    vle8.v     v8, (a4)
    vpnclipu.wv v8, v2, v1, v0.t
    vse8.v     v8, (a2)
    ret
    .size   test_vpnclipu_wv, .-test_vpnclipu_wv

TEST_FUNC(test_vpnclip_wx)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v2, (a1)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v0, (a3)
    vle8.v     v8, (a4)
    vpnclip.wx v8, v2, a0, v0.t
    vse8.v     v8, (a2)
    ret
    .size   test_vpnclip_wx, .-test_vpnclip_wx

TEST_FUNC(test_vpnclipu_wx)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v2, (a1)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v0, (a3)
    vle8.v     v8, (a4)
    vpnclipu.wx v8, v2, a0, v0.t
    vse8.v     v8, (a2)
    ret
    .size   test_vpnclipu_wx, .-test_vpnclipu_wx

TEST_FUNC(test_vpwadd_vv)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v8, (a4)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v1, (a0)
    vle8.v     v2, (a1)
    vle8.v     v0, (a3)
    vpwadd.vv  v8, v2, v1, v0.t
    vsetvli    t0, t0, e16, m2, tu, mu
    vse16.v    v8, (a2)
    ret
    .size   test_vpwadd_vv, .-test_vpwadd_vv

TEST_FUNC(test_vpwaddu_vv)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v8, (a4)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v1, (a0)
    vle8.v     v2, (a1)
    vle8.v     v0, (a3)
    vpwaddu.vv  v8, v2, v1, v0.t
    vsetvli    t0, t0, e16, m2, tu, mu
    vse16.v    v8, (a2)
    ret
    .size   test_vpwaddu_vv, .-test_vpwaddu_vv

TEST_FUNC(test_vpwadd_vx)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v8, (a4)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v2, (a1)
    vle8.v     v0, (a3)
    vpwadd.vx  v8, v2, a0, v0.t
    vsetvli    t0, t0, e16, m2, tu, mu
    vse16.v    v8, (a2)
    ret
    .size   test_vpwadd_vx, .-test_vpwadd_vx

TEST_FUNC(test_vpwaddu_vx)
    li         t0, 16 
    vsetvli    t0, t0, e16, m2, tu, mu
    vle16.v    v8, (a4)
    vsetvli    t0, t0, e8, m1, tu, mu
    vle8.v     v2, (a1)
    vle8.v     v0, (a3)
    vpwaddu.vx  v8, v2, a0, v0.t
    vsetvli    t0, t0, e16, m2, tu, mu
    vse16.v    v8, (a2)
    ret
    .size   test_vpwaddu_vx, .-test_vpwaddu_vx
