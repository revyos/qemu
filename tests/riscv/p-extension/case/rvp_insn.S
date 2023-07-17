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

   .file   "rvp_insn.S"
#undef TEST_FUNC
#define TEST_FUNC(name) TEST_FUNC_M name
    .macro TEST_FUNC_M name
    .text
    .align  2
    .global \name
    .type   \name, @function
\name:
    .endm

TEST_FUNC(test_add16)
    add16   a0, a0, a1
    ret
    .size   test_add16, .-test_add16

TEST_FUNC(test_radd16)
    radd16  a0, a0, a1
    ret
    .size   test_radd16, .-test_radd16

TEST_FUNC(test_uradd16)
    uradd16   a0, a0, a1
    ret
    .size   test_uradd16, .-test_uradd16

TEST_FUNC(test_kadd16)
    kadd16  a0, a0, a1
    ret
    .size   test_kadd16, .-test_kadd16

TEST_FUNC(test_ukadd16)
    ukadd16  a0, a0, a1
    ret
    .size   test_uradd16, .-test_ukadd16

TEST_FUNC(test_sub16)
    sub16   a0, a0, a1
    ret
    .size   test_sub16, .-test_sub16

TEST_FUNC(test_rsub16)
    rsub16  a0, a0, a1
    ret
    .size   test_rsub16, .-test_rsub16

TEST_FUNC(test_ursub16)
    ursub16   a0, a0, a1
    ret
    .size   test_ursub16, .-test_ursub16

TEST_FUNC(test_ksub16)
    ksub16  a0, a0, a1
    ret
    .size   test_ksub16, .-test_ksub16

TEST_FUNC(test_uksub16)
    uksub16  a0, a0, a1
    ret
    .size   test_ursub16, .-test_uksub16

TEST_FUNC(test_cras16)
    cras16   a0, a0, a1
    ret
    .size   test_cras16, .-test_cras16

TEST_FUNC(test_rcras16)
    rcras16  a0, a0, a1
    ret
    .size   test_rcras16, .-test_rcras16

TEST_FUNC(test_urcras16)
    urcras16   a0, a0, a1
    ret
    .size   test_urcras16, .-test_urcras16

TEST_FUNC(test_kcras16)
    kcras16  a0, a0, a1
    ret
    .size   test_kcras16, .-test_kcras16

TEST_FUNC(test_ukcras16)
    ukcras16  a0, a0, a1
    ret
    .size   test_urcras16, .-test_ukcras16

TEST_FUNC(test_crsa16)
    crsa16   a0, a0, a1
    ret
    .size   test_crsa16, .-test_crsa16

TEST_FUNC(test_rcrsa16)
    rcrsa16  a0, a0, a1
    ret
    .size   test_rcrsa16, .-test_rcrsa16

TEST_FUNC(test_urcrsa16)
    urcrsa16   a0, a0, a1
    ret
    .size   test_urcrsa16, .-test_urcrsa16

TEST_FUNC(test_kcrsa16)
    kcrsa16  a0, a0, a1
    ret
    .size   test_kcrsa16, .-test_kcrsa16

TEST_FUNC(test_ukcrsa16)
    ukcrsa16  a0, a0, a1
    ret
    .size   test_urcrsa16, .-test_ukcrsa16

TEST_FUNC(test_stas16)
    stas16   a0, a0, a1
    ret
    .size   test_stas16, .-test_stas16

TEST_FUNC(test_rstas16)
    rstas16  a0, a0, a1
    ret
    .size   test_rstas16, .-test_rstas16

TEST_FUNC(test_urstas16)
    urstas16   a0, a0, a1
    ret
    .size   test_urstas16, .-test_urstas16

TEST_FUNC(test_kstas16)
    kstas16  a0, a0, a1
    ret
    .size   test_kstas16, .-test_kstas16

TEST_FUNC(test_ukstas16)
    ukstas16  a0, a0, a1
    ret
    .size   test_urstas16, .-test_ukstas16

TEST_FUNC(test_stsa16)
    stsa16   a0, a0, a1
    ret
    .size   test_stsa16, .-test_stsa16

TEST_FUNC(test_rstsa16)
    rstsa16  a0, a0, a1
    ret
    .size   test_rstsa16, .-test_rstsa16

TEST_FUNC(test_urstsa16)
    urstsa16   a0, a0, a1
    ret
    .size   test_urstsa16, .-test_urstsa16

TEST_FUNC(test_kstsa16)
    kstsa16  a0, a0, a1
    ret
    .size   test_kstsa16, .-test_kstsa16

TEST_FUNC(test_ukstsa16)
    ukstsa16  a0, a0, a1
    ret
    .size   test_urstsa16, .-test_ukstsa16

TEST_FUNC(test_add8)
    add8   a0, a0, a1
    ret
    .size   test_add8, .-test_add8

TEST_FUNC(test_radd8)
    radd8  a0, a0, a1
    ret
    .size   test_radd8, .-test_radd8

TEST_FUNC(test_uradd8)
    uradd8  a0, a0, a1
    ret
    .size   test_uradd8, .-test_uradd8

TEST_FUNC(test_kadd8)
    kadd8  a0, a0, a1
    ret
    .size   test_kadd8, .-test_kadd8

TEST_FUNC(test_ukadd8)
    ukadd8  a0, a0, a1
    ret
    .size   test_ukadd8, .-test_ukadd8

TEST_FUNC(test_sub8)
    sub8   a0, a0, a1
    ret
    .size   test_sub8, .-test_sub8

TEST_FUNC(test_rsub8)
    rsub8  a0, a0, a1
    ret
    .size   test_rsub8, .-test_rsub8

TEST_FUNC(test_ursub8)
    ursub8  a0, a0, a1
    ret
    .size   test_ursub8, .-test_ursub8

TEST_FUNC(test_ksub8)
    ksub8  a0, a0, a1
    ret
    .size   test_ksub8, .-test_ksub8

TEST_FUNC(test_uksub8)
    uksub8  a0, a0, a1
    ret
    .size   test_uksub8, .-test_uksub8

TEST_FUNC(test_sra16)
    sra16  a0, a0, a1
    ret
    .size   test_sra16, .-test_sra16

TEST_FUNC(test_srai16_1)
    srai16  a0, a0, 0x1
    ret
    .size   test_srai16_1, .-test_srai16_1

TEST_FUNC(test_srai16_2)
    srai16  a0, a0, 0x2
    ret
    .size   test_srai16_2, .-test_srai16_2

TEST_FUNC(test_srai16_15)
    srai16  a0, a0, 0xf
    ret
    .size   test_srai16_15, .-test_srai16_15

TEST_FUNC(test_sra16_u)
    sra16.u  a0, a0, a1
    ret
    .size   test_sra16_u, .-test_sra16_u

TEST_FUNC(test_srai16_u_1)
    srai16.u  a0, a0, 0x1
    ret
    .size   test_srai16_u_1, .-test_srai16_u_1

TEST_FUNC(test_srai16_u_2)
    srai16.u  a0, a0, 0x2
    ret
    .size   test_srai16_u_2, .-test_srai16_u_2

TEST_FUNC(test_srl16)
    srl16  a0, a0, a1
    ret
    .size   test_srl16, .-test_srl16

TEST_FUNC(test_srli16_1)
    srli16  a0, a0, 0x1
    ret
    .size   test_srli16_1, .-test_srli16_1

TEST_FUNC(test_srli16_2)
    srli16  a0, a0, 0x2
    ret
    .size   test_srli16_2, .-test_srli16_2

TEST_FUNC(test_srli16_3)
    srli16  a0, a0, 0x3
    ret
    .size   test_srli16_3, .-test_srli16_3

TEST_FUNC(test_srli16_15)
    srli16  a0, a0, 0xf
    ret
    .size   test_srli16_15, .-test_srli16_15

TEST_FUNC(test_srl16_u)
    srl16.u  a0, a0, a1
    ret
    .size   test_srl16_u, .-test_srl16_u

TEST_FUNC(test_srli16_u_1)
    srli16.u  a0, a0, 0x1
    ret
    .size   test_srli16_u_1, .-test_srli16_u_1

TEST_FUNC(test_srli16_u_2)
    srli16.u  a0, a0, 0x2
    ret
    .size   test_srli16_u_2, .-test_srli16_u_2

TEST_FUNC(test_srli16_u_3)
    srli16.u  a0, a0, 0x3
    ret
    .size   test_srli16_u_3, .-test_srli16_u_3

TEST_FUNC(test_srli16_u_15)
    srli16.u  a0, a0, 0xf
    ret
    .size   test_srli16_u_15, .-test_srli16_u_15

TEST_FUNC(test_sll16)
    sll16  a0, a0, a1
    ret
    .size   test_sll16, .-test_sll16

TEST_FUNC(test_slli16_1)
    slli16  a0, a0, 0x1
    ret
    .size   test_slli16_1, .-test_slli16_1

TEST_FUNC(test_slli16_9)
    slli16  a0, a0, 0x9
    ret
    .size   test_slli16_9, .-test_slli16_9

TEST_FUNC(test_ksll16)
    ksll16  a0, a0, a1
    ret
    .size   test_ksll16, .-test_ksll16

TEST_FUNC(test_kslli16_1)
    kslli16  a0, a0, 0x1
    ret
    .size   test_kslli16_1, .-test_kslli16_1

TEST_FUNC(test_kslli16_2)
    kslli16  a0, a0, 0x2
    ret
    .size   test_kslli16_2, .-test_kslli16_2

TEST_FUNC(test_kslli16_9)
    kslli16  a0, a0, 0x9
    ret
    .size   test_kslli16_9, .-test_kslli16_9

TEST_FUNC(test_kslra16)
    kslra16  a0, a0, a1
    ret
    .size   test_kslra16, .-test_kslra16

TEST_FUNC(test_kslra16_u)
    kslra16.u  a0, a0, a1
    ret
    .size   test_kslra16_u, .-test_kslra16_u

TEST_FUNC(test_sra8)
    sra8  a0, a0, a1
    ret
    .size   test_sra8, .-test_sra8

TEST_FUNC(test_srai8_1)
    srai8  a0, a0, 0x1
    ret
    .size   test_srai8_1, .-test_srai8_1

TEST_FUNC(test_srai8_2)
    srai8  a0, a0, 0x2
    ret
    .size   test_srai8_2, .-test_srai8_2

TEST_FUNC(test_srai8_3)
    srai8  a0, a0, 0x3
    ret
    .size   test_srai8_3, .-test_srai8_3

TEST_FUNC(test_srai8_4)
    srai8  a0, a0, 0x4
    ret
    .size   test_srai8_4, .-test_srai8_4

TEST_FUNC(test_srai8_7)
    srai8  a0, a0, 0x7
    ret
    .size   test_srai8_7, .-test_srai8_7

TEST_FUNC(test_sra8_u)
    sra8.u  a0, a0, a1
    ret
    .size   test_sra8_u, .-test_sra8_u

TEST_FUNC(test_srai8_u_1)
    srai8.u  a0, a0, 0x1
    ret
    .size   test_srai8_u_1, .-test_srai8_u_1

TEST_FUNC(test_srai8_u_2)
    srai8.u  a0, a0, 0x2
    ret
    .size   test_srai8_u_2, .-test_srai8_u_2

TEST_FUNC(test_srai8_u_3)
    srai8.u  a0, a0, 0x3
    ret
    .size   test_srai8_u_3, .-test_srai8_u_3

TEST_FUNC(test_srai8_u_4)
    srai8.u  a0, a0, 0x4
    ret
    .size   test_srai8_u_4, .-test_srai8_u_4

TEST_FUNC(test_srai8_u_7)
    srai8.u  a0, a0, 0x7
    ret
    .size   test_srai8_u_7, .-test_srai8_u_7

TEST_FUNC(test_srl8)
    srl8  a0, a0, a1
    ret
    .size   test_srl8, .-test_srl8

TEST_FUNC(test_srli8_1)
    srli8  a0, a0, 0x1
    ret
    .size   test_srli8_1, .-test_srli8_1

TEST_FUNC(test_srli8_2)
    srli8  a0, a0, 0x2
    ret
    .size   test_srli8_2, .-test_srli8_2

TEST_FUNC(test_srli8_3)
    srli8  a0, a0, 0x3
    ret
    .size   test_srli8_3, .-test_srli8_3

TEST_FUNC(test_srli8_4)
    srli8  a0, a0, 0x4
    ret
    .size   test_srli8_4, .-test_srli8_4

TEST_FUNC(test_srli8_7)
    srli8  a0, a0, 0x7
    ret
    .size   test_srli8_7, .-test_srli8_7

TEST_FUNC(test_srl8_u)
    srl8.u  a0, a0, a1
    ret
    .size   test_srl8_u, .-test_srl8_u

TEST_FUNC(test_srli8_u_1)
    srli8.u  a0, a0, 0x1
    ret
    .size   test_srli8_u_1, .-test_srli8_u_1

TEST_FUNC(test_srli8_u_2)
    srli8.u  a0, a0, 0x2
    ret
    .size   test_srli8_u_2, .-test_srli8_u_2

TEST_FUNC(test_srli8_u_3)
    srli8.u  a0, a0, 0x3
    ret
    .size   test_srli8_u_3, .-test_srli8_u_3

TEST_FUNC(test_srli8_u_4)
    srli8.u  a0, a0, 0x4
    ret
    .size   test_srli8_u_4, .-test_srli8_u_4

TEST_FUNC(test_srli8_u_7)
    srli8.u  a0, a0, 0x7
    ret
    .size   test_srli8_u_7, .-test_srli8_u_7

TEST_FUNC(test_sll8)
    sll8  a0, a0, a1
    ret
    .size   test_sll8, .-test_sll8

TEST_FUNC(test_slli8_1)
    slli8  a0, a0, 0x1
    ret
    .size   test_slli8_1, .-test_slli8_1

TEST_FUNC(test_slli8_2)
    slli8  a0, a0, 0x2
    ret
    .size   test_slli8_2, .-test_slli8_2

TEST_FUNC(test_slli8_3)
    slli8  a0, a0, 0x3
    ret
    .size   test_slli8_3, .-test_slli8_3

TEST_FUNC(test_slli8_4)
    slli8  a0, a0, 0x4
    ret
    .size   test_slli8_4, .-test_slli8_4

TEST_FUNC(test_slli8_7)
    slli8  a0, a0, 0x7
    ret
    .size   test_slli8_7, .-test_slli8_7

TEST_FUNC(test_ksll8)
    ksll8  a0, a0, a1
    ret
    .size   test_ksll8, .-test_ksll8

TEST_FUNC(test_kslli8_1)
    kslli8  a0, a0, 0x1
    ret
    .size   test_kslli8_1, .-test_kslli8_1

TEST_FUNC(test_kslli8_2)
    kslli8  a0, a0, 0x2
    ret
    .size   test_kslli8_2, .-test_kslli8_2

TEST_FUNC(test_kslli8_3)
    kslli8  a0, a0, 0x3
    ret
    .size   test_kslli8_3, .-test_kslli8_3

TEST_FUNC(test_kslli8_4)
    kslli8  a0, a0, 0x4
    ret
    .size   test_kslli8_4, .-test_kslli8_4

TEST_FUNC(test_kslli8_7)
    kslli8  a0, a0, 0x7
    ret
    .size   test_kslli8_7, .-test_kslli8_7

TEST_FUNC(test_kslra8)
    kslra8  a0, a0, a1
    ret
    .size   test_kslra8, .-test_kslra8

TEST_FUNC(test_kslra8_u)
    kslra8.u  a0, a0, a1
    ret
    .size   test_kslra8_u, .-test_kslra8_u

TEST_FUNC(test_cmpeq16)
    cmpeq16  a0, a0, a1
    ret
    .size   test_cmpeq16, .-test_cmpeq16

TEST_FUNC(test_scmplt16)
    scmplt16  a0, a0, a1
    ret
    .size   test_scmplt16, .-test_scmplt16

TEST_FUNC(test_scmple16)
    scmple16  a0, a0, a1
    ret
    .size   test_scmple16, .-test_scmple16

TEST_FUNC(test_ucmplt16)
    ucmplt16  a0, a0, a1
    ret
    .size   test_ucmplt16, .-test_ucmplt16

TEST_FUNC(test_ucmple16)
    ucmple16  a0, a0, a1
    ret
    .size   test_ucmple16, .-test_ucmple16

TEST_FUNC(test_cmpeq8)
    cmpeq8  a0, a0, a1
    ret
    .size   test_cmpeq8, .-test_cmpeq8

TEST_FUNC(test_scmplt8)
    scmplt8  a0, a0, a1
    ret
    .size   test_scmplt8, .-test_scmplt8

TEST_FUNC(test_scmple8)
    scmple8  a0, a0, a1
    ret
    .size   test_scmple8, .-test_scmple8

TEST_FUNC(test_ucmplt8)
    ucmplt8  a0, a0, a1
    ret
    .size   test_ucmplt8, .-test_ucmplt8

TEST_FUNC(test_ucmple8)
    ucmple8  a0, a0, a1
    ret
    .size   test_ucmple8, .-test_ucmple8

TEST_FUNC(test_smul16)
    smul16   a0, a0, a1
    ret
    .size   test_smul16, .-test_smul16

TEST_FUNC(test_smulx16)
    smulx16   a0, a0, a1
    ret
    .size   test_smulx16, .-test_smulx16

TEST_FUNC(test_umul16)
    umul16   a0, a0, a1
    ret
    .size   test_umul16, .-test_umul16

TEST_FUNC(test_umulx16)
    umulx16   a0, a0, a1
    ret
    .size   test_umulx16, .-test_umulx16

TEST_FUNC(test_khm16)
    khm16    a0, a0, a1
    ret
    .size   test_khm16, .-test_khm16

TEST_FUNC(test_khmx16)
    khmx16    a0, a0, a1
    ret
    .size   test_khmx16, .-test_khmx16

TEST_FUNC(test_smul8)
    smul8   a0, a0, a1
    ret
    .size   test_smul8, .-test_smul8

TEST_FUNC(test_smulx8)
    smulx8   a0, a0, a1
    ret
    .size   test_smulx8, .-test_smulx8

TEST_FUNC(test_umul8)
    umul8   a0, a0, a1
    ret
    .size   test_umul8, .-test_umul8

TEST_FUNC(test_umulx8)
    umulx8   a0, a0, a1
    ret
    .size   test_umulx8, .-test_umulx8

TEST_FUNC(test_khm8)
    khm8    a0, a0, a1
    ret
    .size   test_khm8, .-test_khm8

TEST_FUNC(test_khmx8)
    khmx8    a0, a0, a1
    ret
    .size   test_khmx8, .-test_khmx8

TEST_FUNC(test_smin16)
    smin16    a0, a0, a1
    ret
    .size   test_smin16, .-test_smin16

TEST_FUNC(test_umin16)
    umin16    a0, a0, a1
    ret
    .size   test_umin16, .-test_umin16

TEST_FUNC(test_smax16)
    smax16    a0, a0, a1
    ret
    .size   test_smax16, .-test_smax16

TEST_FUNC(test_umax16)
    umax16    a0, a0, a1
    ret
    .size   test_umax16, .-test_umax16

TEST_FUNC(test_sclip16_1)
    sclip16    a0, a0, 0x1
    ret
    .size   test_sclip16_1, .-test_sclip16_1

TEST_FUNC(test_sclip16_2)
    sclip16    a0, a0, 0x2
    ret
    .size   test_sclip16_2, .-test_sclip16_2

TEST_FUNC(test_sclip16_8)
    sclip16    a0, a0, 0x8
    ret
    .size   test_sclip16_8, .-test_sclip16_8

TEST_FUNC(test_sclip16_14)
    sclip16    a0, a0, 0xe
    ret
    .size   test_sclip16_14, .-test_sclip16_14

TEST_FUNC(test_sclip16_15)
    sclip16    a0, a0, 0xf
    ret
    .size   test_sclip16_15, .-test_sclip16_15

TEST_FUNC(test_uclip16_1)
    uclip16    a0, a0, 0x1
    ret
    .size   test_uclip16_1, .-test_uclip16_1

TEST_FUNC(test_uclip16_2)
    uclip16    a0, a0, 0x2
    ret
    .size   test_uclip16_2, .-test_uclip16_2

TEST_FUNC(test_uclip16_8)
    uclip16    a0, a0, 0x8
    ret
    .size   test_uclip16_8, .-test_uclip16_8

TEST_FUNC(test_uclip16_14)
    uclip16    a0, a0, 0xe
    ret
    .size   test_uclip16_14, .-test_uclip16_14

TEST_FUNC(test_uclip16_15)
    uclip16    a0, a0, 0xf
    ret
    .size   test_uclip16_15, .-test_uclip16_15

TEST_FUNC(test_kabs16)
    kabs16    a0, a0
    ret
    .size   test_kabs16, .-test_kabs16

TEST_FUNC(test_clrs16)
    clrs16    a0, a0
    ret
    .size   test_clrs16, .-test_clrs16

TEST_FUNC(test_clz16)
    clz16    a0, a0
    ret
    .size   test_clz16, .-test_clz16

TEST_FUNC(test_clo16)
    clo16    a0, a0
    ret
    .size   test_clo16, .-test_clo16

TEST_FUNC(test_smin8)
    smin8    a0, a0, a1
    ret
    .size   test_smin8, .-test_smin8

TEST_FUNC(test_umin8)
    umin8    a0, a0, a1
    ret
    .size   test_umin8, .-test_umin8

TEST_FUNC(test_smax8)
    smax8    a0, a0, a1
    ret
    .size   test_smax8, .-test_smax8

TEST_FUNC(test_umax8)
    umax8    a0, a0, a1
    ret
    .size   test_umax8, .-test_umax8

TEST_FUNC(test_sclip8_1)
    sclip8    a0, a0, 0x1
    ret
    .size   test_sclip8_1, .-test_sclip8_1

TEST_FUNC(test_sclip8_2)
    sclip8    a0, a0, 0x2
    ret
    .size   test_sclip8_2, .-test_sclip8_2

TEST_FUNC(test_sclip8_3)
    sclip8    a0, a0, 0x3
    ret
    .size   test_sclip8_3, .-test_sclip8_3

TEST_FUNC(test_sclip8_6)
    sclip8    a0, a0, 0x6
    ret
    .size   test_sclip8_6, .-test_sclip8_6

TEST_FUNC(test_sclip8_7)
    sclip8    a0, a0, 0x7
    ret
    .size   test_sclip8_7, .-test_sclip8_7

TEST_FUNC(test_uclip8_1)
    uclip8    a0, a0, 0x1
    ret
    .size   test_uclip8_1, .-test_uclip8_1

TEST_FUNC(test_uclip8_2)
    uclip8    a0, a0, 0x2
    ret
    .size   test_uclip8_2, .-test_uclip8_2

TEST_FUNC(test_uclip8_3)
    uclip8    a0, a0, 0x3
    ret
    .size   test_uclip8_3, .-test_uclip8_3

TEST_FUNC(test_uclip8_6)
    uclip8    a0, a0, 0x6
    ret
    .size   test_uclip8_6, .-test_uclip8_6

TEST_FUNC(test_uclip8_7)
    uclip8    a0, a0, 0x7
    ret
    .size   test_uclip8_7, .-test_uclip8_7

TEST_FUNC(test_kabs8)
    kabs8    a0, a0
    ret
    .size   test_kabs8, .-test_kabs8

TEST_FUNC(test_clrs8)
    clrs8    a0, a0
    ret
    .size   test_clrs8, .-test_clrs8

TEST_FUNC(test_clz8)
    clz8    a0, a0
    ret
    .size   test_clz8, .-test_clz8

TEST_FUNC(test_clo8)
    clo8    a0, a0
    ret
    .size   test_clo8, .-test_clo8

TEST_FUNC(test_sunpkd810)
    sunpkd810    a0, a0
    ret
    .size   test_sunpkd810, .-test_sunpkd810

TEST_FUNC(test_sunpkd820)
    sunpkd820    a0, a0
    ret
    .size   test_sunpkd820, .-test_sunpkd820

TEST_FUNC(test_sunpkd830)
    sunpkd830    a0, a0
    ret
    .size   test_sunpkd830, .-test_sunpkd830

TEST_FUNC(test_sunpkd831)
    sunpkd831    a0, a0
    ret
    .size   test_sunpkd831, .-test_sunpkd831

TEST_FUNC(test_sunpkd832)
    sunpkd832    a0, a0
    ret
    .size   test_sunpkd832, .-test_sunpkd832

TEST_FUNC(test_zunpkd810)
    zunpkd810    a0, a0
    ret
    .size   test_zunpkd810, .-test_zunpkd810

TEST_FUNC(test_zunpkd820)
    zunpkd820    a0, a0
    ret
    .size   test_zunpkd820, .-test_zunpkd820

TEST_FUNC(test_zunpkd830)
    zunpkd830    a0, a0
    ret
    .size   test_zunpkd830, .-test_zunpkd830

TEST_FUNC(test_zunpkd831)
    zunpkd831    a0, a0
    ret
    .size   test_zunpkd831, .-test_zunpkd831

TEST_FUNC(test_zunpkd832)
    zunpkd832    a0, a0
    ret
    .size   test_zunpkd832, .-test_zunpkd832

TEST_FUNC(test_pkbb16)
    pkbb16    a0, a0, a1
    ret
    .size   test_pkbb16, .-test_pkbb16

TEST_FUNC(test_pkbt16)
    pkbt16    a0, a0, a1
    ret
    .size   test_pkbt16, .-test_pkbt16

TEST_FUNC(test_pktt16)
    pktt16    a0, a0, a1
    ret
    .size   test_pktt16, .-test_pktt16

TEST_FUNC(test_pktb16)
    pktb16    a0, a0, a1
    ret
    .size   test_pktb16, .-test_pktb16

TEST_FUNC(test_smmul)
    smmul    a0, a0, a1
    ret
    .size   test_smmul, .-test_smmul

TEST_FUNC(test_smmul_u)
    smmul.u    a0, a0, a1
    ret
    .size   test_smmul_u, .-test_smmul_u

TEST_FUNC(test_kmmac)
    kmmac    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmmac, .-test_kmmac

TEST_FUNC(test_kmmac_u)
    kmmac.u    a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kmmac_u, .-test_kmmac_u

TEST_FUNC(test_kmmsb)
    kmmsb    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmmsb, .-test_kmmsb

TEST_FUNC(test_kmmsb_u)
    kmmsb.u    a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kmmsb_u, .-test_kmmsb_u

TEST_FUNC(test_kwmmul)
    kwmmul    a0, a0, a1
    ret
    .size   test_kwmmul, .-test_kwmmul

TEST_FUNC(test_kwmmul_u)
    kwmmul.u    a0, a0, a1
    ret
    .size   test_kwmmul_u, .-test_kwmmul_u

TEST_FUNC(test_smmwb)
    smmwb    a0, a0, a1
    ret
    .size   test_smmwb, .-test_smmwb

TEST_FUNC(test_smmwb_u)
    smmwb.u    a0, a0, a1
    ret
    .size   test_smmwb_u, .-test_smmwb_u

TEST_FUNC(test_smmwt)
    smmwt    a0, a0, a1
    ret
    .size   test_smmwt, .-test_smmwt

TEST_FUNC(test_smmwt_u)
    smmwt.u    a0, a0, a1
    ret
    .size   test_smmwt_u, .-test_smmwt_u

TEST_FUNC(test_kmmawb)
    kmmawb    a2, a0, a1
    mv        a0, a2
    ret
    .size   test_kmmawb, .-test_kmmawb

TEST_FUNC(test_kmmawb_u)
    kmmawb.u    a2, a0, a1
    mv          a0, a2
    ret
    .size   test_kmmawb_u, .-test_kmmawb_u

TEST_FUNC(test_kmmawt)
    kmmawt    a2, a0, a1
    mv        a0, a2
    ret
    .size   test_kmmawt, .-test_kmmawt

TEST_FUNC(test_kmmawt_u)
    kmmawt.u    a2, a0, a1
    mv          a0, a2
    ret
    .size   test_kmmawt_u, .-test_kmmawt_u

TEST_FUNC(test_kmmwb2)
    kmmwb2    a0, a0, a1
    ret
    .size   test_kmmwb2, .-test_kmmwb2

TEST_FUNC(test_kmmwb2_u)
    kmmwb2.u    a0, a0, a1
    ret
    .size   test_kmmwb2_u, .-test_kmmwb2_u

TEST_FUNC(test_kmmwt2)
    kmmwt2    a0, a0, a1
    ret
    .size   test_kmmwt2, .-test_kmmwt2

TEST_FUNC(test_kmmwt2_u)
    kmmwt2.u    a0, a0, a1
    ret
    .size   test_kmmwt2_u, .-test_kmmwt2_u

TEST_FUNC(test_kmmawb2)
    kmmawb2    a2, a0, a1
    mv        a0, a2
    ret
    .size   test_kmmawb2, .-test_kmmawb2

TEST_FUNC(test_kmmawb2_u)
    kmmawb2.u    a2, a0, a1
    mv          a0, a2
    ret
    .size   test_kmmawb2_u, .-test_kmmawb2_u

TEST_FUNC(test_kmmawt2)
    kmmawt2    a2, a0, a1
    mv        a0, a2
    ret
    .size   test_kmmawt2, .-test_kmmawt2

TEST_FUNC(test_kmmawt2_u)
    kmmawt2.u    a2, a0, a1
    mv          a0, a2
    ret
    .size   test_kmmawt2_u, .-test_kmmawt2_u
#ifdef RV64
TEST_FUNC(test_add32)
    add32   a0, a0, a1
    ret
    .size   test_add32, .-test_add32

TEST_FUNC(test_cras32)
    cras32   a0, a0, a1
    ret
    .size   test_cras32, .-test_add32

TEST_FUNC(test_crsa32)
    crsa32   a0, a0, a1
    ret
    .size   test_crsa32, .-test_crsa32

TEST_FUNC(test_kabs32)
    kabs32   a0, a0
    ret
    .size   test_kabs32, .-test_kabs32

TEST_FUNC(test_kadd32)
    kadd32   a0, a0, a1
    ret
    .size   test_kadd32, .-test_kadd32

TEST_FUNC(test_kcras32)
    kcras32   a0, a0, a1
    ret
    .size   test_kcras32, .-test_kcras32

TEST_FUNC(test_kcrsa32)
    kcrsa32   a0, a0, a1
    ret
    .size   test_kcrsa32, .-test_kcrsa32

TEST_FUNC(test_kdmbb16)
    kdmbb16   a0, a0, a1
    ret
    .size   test_kdmbb16, .-test_kdmbb16

TEST_FUNC(test_kdmbt16)
    kdmbt16   a0, a0, a1
    ret
    .size   test_kdmbt16, .-test_kdmbt16

TEST_FUNC(test_kdmtt16)
    kdmtt16   a0, a0, a1
    ret
    .size   test_kdmtt16, .-test_kdmtt16

TEST_FUNC(test_srai32_0)
    srai32    a0, a0, 0
    ret
    .size   test_srai32_0, .-test_srai32_0

TEST_FUNC(test_srai32_1)
    srai32    a0, a0, 1
    ret
    .size   test_srai32_1, .-test_srai32_1

TEST_FUNC(test_srai32_2)
    srai32    a0, a0, 2
    ret
    .size   test_srai32_2, .-test_srai32_2

TEST_FUNC(test_srai32_31)
    srai32    a0, a0, 31
    ret
    .size   test_srai32_31, .-test_srai32_31

TEST_FUNC(test_srai32_u_0)
    srai32.u    a0, a0, 0
    ret
    .size   test_srai32_u_0, .-test_srai32_u_0

TEST_FUNC(test_srai32_u_1)
    srai32.u    a0, a0, 1
    ret
    .size   test_srai32_1, .-test_srai32_u_1

TEST_FUNC(test_srai32_u_2)
    srai32.u    a0, a0, 2
    ret
    .size   test_srai32_2, .-test_srai32_u_2

TEST_FUNC(test_srai32_u_31)
    srai32.u    a0, a0, 31
    ret
    .size   test_srai32_31, .-test_srai32_u_31

TEST_FUNC(test_srl32)
    srl32   a0, a0, a1
    ret
    .size    test_srl32, .-test_srl32

TEST_FUNC(test_srli32_0)
    srli32    a0, a0, 0
    ret
    .size   test_srli32_0, .-test_srli32_0

TEST_FUNC(test_srli32_1)
    srli32    a0, a0, 1
    ret
    .size   test_srli32_1, .-test_srli32_1

TEST_FUNC(test_srli32_2)
    srli32    a0, a0, 2
    ret
    .size   test_srli32_2, .-test_srli32_2

TEST_FUNC(test_srli32_31)
    srli32    a0, a0, 31
    ret
    .size   test_srli32_31, .-test_srli32_31

TEST_FUNC(test_srli32_u_0)
    srli32.u    a0, a0, 0
    ret
    .size   test_srli32_u_0, .-test_srli32_u_0

TEST_FUNC(test_srli32_u_1)
    srli32.u    a0, a0, 1
    ret
    .size   test_srli32_u_1, .-test_srli32_u_1

TEST_FUNC(test_srli32_u_2)
    srli32.u    a0, a0, 2
    ret
    .size   test_srli32_u_2, .-test_srli32_u_2

TEST_FUNC(test_srli32_u_31)
    srli32.u    a0, a0, 31
    ret
    .size   test_srli32_u_31, .-test_srli32_u_31


TEST_FUNC(test_sra32)
    sra32   a0, a0, a1
    ret
    .size    test_sra32, .-test_sra32

TEST_FUNC(test_sra32_u)
    sra32.u a0, a0, a1
    ret
    .size    test_sra32_u, .-test_sra32_u

TEST_FUNC(test_srl32_u)
    srl32.u a0, a0, a1
    ret
    .size    test_srl32_u, .-test_srl32_u

TEST_FUNC(test_sll32)
    sll32  a0, a0, a1
    ret
    .size    test_sll32, .-test_sll32

TEST_FUNC(test_ksll32)
    ksll32  a0, a0, a1
    ret
    .size    test_ksll32, .-test_ksll32

TEST_FUNC(test_kslli32_0)
    kslli32    a0, a0, 0
    ret
    .size   test_kslli32_0, .-test_kslli32_0

TEST_FUNC(test_kslli32_1)
    kslli32    a0, a0, 1
    ret
    .size   test_kslli32_1, .-test_kslli32_1

TEST_FUNC(test_kslli32_2)
    kslli32    a0, a0, 2
    ret
    .size   test_kslli32_2, .-test_kslli32_2

TEST_FUNC(test_kslli32_9)
    kslli32    a0, a0, 9
    ret
    .size   test_kslli32_9, .-test_kslli32_9

TEST_FUNC(test_kslli32_31)
    kslli32    a0, a0, 31
    ret
    .size   test_kslli32_31, .-test_kslli32_31

TEST_FUNC(test_kslra32)
    kslra32 a0, a0, a1
    ret
    .size    test_kslra32, .-test_kslra32

TEST_FUNC(test_kslra32_u)
    kslra32.u   a0, a0, a1
    ret
    .size    test_kslra32_u, .-test_kslra32_u

TEST_FUNC(test_slli32_0)
    slli32    a0, a0, 0
    ret
    .size   test_slli32_0, .-test_slli32_0

TEST_FUNC(test_slli32_1)
    slli32    a0, a0, 1
    ret
    .size   test_slli32_1, .-test_slli32_1

TEST_FUNC(test_slli32_2)
    slli32    a0, a0, 2
    ret
    .size   test_slli32_2, .-test_slli32_2

TEST_FUNC(test_slli32_4)
    slli32    a0, a0,4
    ret
    .size   test_slli32_4, .-test_slli32_4

TEST_FUNC(test_slli32_9)
    slli32    a0, a0, 9
    ret
    .size   test_slli32_9, .-test_slli32_9

TEST_FUNC(test_slli32_31)
    slli32    a0, a0, 31
    ret
    .size   test_slli32_31, .-test_slli32_31

TEST_FUNC(test_radd32)
    radd32    a0, a0, a1
    ret
    .size    test_radd32, .-test_radd32

TEST_FUNC(test_kdmabb16)
    kdmabb16    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kdmabb16, .-test_kdmabb16

TEST_FUNC(test_kdmabt16)
    kdmabt16    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kdmabt16, .-test_kdmabt16

TEST_FUNC(test_kdmatt16)
    kdmatt16    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kdmatt16, .-test_kdmatt16

TEST_FUNC(test_khmbb16)
    khmbb16    a0, a0, a1
    ret
    .size    test_khmbb16, .-test_khmbb16

TEST_FUNC(test_khmbt16)
    khmbt16    a0, a0, a1
    ret
    .size    test_khmbt16, .-test_khmbt16

TEST_FUNC(test_khmtt16)
    khmtt16    a0, a0, a1
    ret
    .size    test_khmtt16, .-test_khmtt16

TEST_FUNC(test_kmabb32)
    kmabb32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmabb32, .-test_kmabb32

TEST_FUNC(test_kmabt32)
    kmabt32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmabt32, .-test_kmabt32

TEST_FUNC(test_kmatt32)
    kmatt32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmatt32, .-test_kmatt32

TEST_FUNC(test_kmada32)
    kmada32    a2, a0, a1
    mv  a0, a2
    ret
    .size    test_kmada32, .-test_kmada32

TEST_FUNC(test_kmaxda32)
    kmaxda32    a2, a0, a1
    mv  a0, a2
    ret
    .size    test_kmaxda32, .-test_kmaxda32

TEST_FUNC(test_kmda32)
    kmda32    a0, a0, a1
    ret
    .size    test_kmda32, .-test_kmda32

TEST_FUNC(test_kmxda32)
    kmxda32    a0, a0, a1
    ret
    .size    test_kmxda32, .-test_kmxda32

TEST_FUNC(test_kmads32)
    kmads32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmads32, .-test_kmads32

TEST_FUNC(test_kmadrs32)
    kmadrs32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmadrs32, .-test_kmadrs32

TEST_FUNC(test_kmaxds32)
    kmaxds32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmaxds32, .-test_kmaxds32

TEST_FUNC(test_kmsda32)
    kmsda32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmsda32, .-test_kmsda32

TEST_FUNC(test_kmsxda32)
    kmsxda32    a2, a0, a1
    mv a0, a2
    ret
    .size    test_kmsxda32, .-test_kmsxda32

TEST_FUNC(test_kstas32)
    kstas32    a0, a0, a1
    ret
    .size    test_kstas32, .-test_kstas32

TEST_FUNC(test_kstsa32)
    kstsa32    a0, a0, a1
    ret
    .size    test_kstsa32, .-test_kstsa32

TEST_FUNC(test_ksub32)
    ksub32    a0, a0, a1
    ret
    .size    test_ksub32, .-test_ksub32

TEST_FUNC(test_pkbb32)
    pkbb32    a0, a0, a1
    ret
    .size    test_pkbb32, .-test_pkbb32

TEST_FUNC(test_pkbt32)
    pkbt32    a0, a0, a1
    ret
    .size    test_pkbt32, .-test_pkbt32

TEST_FUNC(test_pktt32)
    pktt32    a0, a0, a1
    ret
    .size    test_pktt32, .-test_pktt32

TEST_FUNC(test_pktb32)
    pktb32    a0, a0, a1
    ret
    .size    test_pktb32, .-test_pktb32

TEST_FUNC(test_rcras32)
    rcras32    a0, a0, a1
    ret
    .size    test_rcras32, .-test_rcras32

TEST_FUNC(test_rcrsa32)
    rcrsa32    a0, a0, a1
    ret
    .size    test_rcrsa32, .-test_rcrsa32

TEST_FUNC(test_rstas32)
    rstas32    a0, a0, a1
    ret
    .size    test_rstas32, .-test_rstas32

TEST_FUNC(test_rstsa32)
    rstsa32    a0, a0, a1
    ret
    .size    test_rstsa32, .-test_rstsa32

TEST_FUNC(test_rsub32)
    rsub32    a0, a0, a1
    ret
    .size    test_rsub32, .-test_rsub32

TEST_FUNC(test_smax32)
    smax32    a0, a0, a1
    ret
    .size    test_smax32, .-test_smax32

//TEST_FUNC(test_smbb32)
//    smbb32    a0, a0, a1
//    ret
//    .size    test_smbb32, .-test_smbb32

TEST_FUNC(test_smbt32)
    smbt32    a0, a0, a1
    ret
    .size    test_smbt32, .-test_smbt32

TEST_FUNC(test_smtt32)
    smtt32    a0, a0, a1
    ret
    .size    test_smtt32, .-test_smtt32

TEST_FUNC(test_smds32)
    smds32    a0, a0, a1
    ret
    .size    test_smds32, .-test_smds32

TEST_FUNC(test_smdrs32)
    smdrs32    a0, a0, a1
    ret
    .size    test_smdrs32, .-test_smdrs32

TEST_FUNC(test_smxds32)
    smxds32    a0, a0, a1
    ret
    .size    test_smxds32, .-test_smxds32

TEST_FUNC(test_smin32)
    smin32    a0, a0, a1
    ret
    .size    test_smin32, .-test_smin32

TEST_FUNC(test_sraiw_u_0)
    sraiw.u    a0, a0, 0
    ret
    .size   test_sraiw_u_0, .-test_sraiw_u_0

TEST_FUNC(test_sraiw_u_1)
    sraiw.u    a0, a0, 1
    ret
    .size   test_sraiw_u_1, .-test_sraiw_u_1

TEST_FUNC(test_sraiw_u_2)
    sraiw.u    a0, a0, 2
    ret
    .size   test_sraiw_u_2, .-test_sraiw_u_2

TEST_FUNC(test_sraiw_u_31)
    sraiw.u    a0, a0, 31
    ret
    .size   test_sraiw_u_31, .-test_sraiw_u_31

TEST_FUNC(test_stas32)
    stas32    a0, a0, a1
    ret
    .size    test_stas32, .-test_stas32

TEST_FUNC(test_stsa32)
    stsa32    a0, a0, a1
    ret
    .size    test_stsa32, .-test_stsa32

TEST_FUNC(test_sub32)
    sub32    a0, a0, a1
    ret
    .size    test_sub32, .-test_sub32

TEST_FUNC(test_ukadd32)
    ukadd32    a0, a0, a1
    ret
    .size    test_ukadd32, .-test_ukadd32

TEST_FUNC(test_ukcras32)
    ukcras32    a0, a0, a1
    ret
    .size    test_ukcras32, .-test_ukcras32

TEST_FUNC(test_ukcrsa32)
    ukcrsa32    a0, a0, a1
    ret
    .size    test_ukcrsa32, .-test_ukcrsa32

TEST_FUNC(test_ukstas32)
    ukstas32    a0, a0, a1
    ret
    .size    test_ukstas32, .-test_ukstas32

TEST_FUNC(test_ukstsa32)
    ukstsa32    a0, a0, a1
    ret
    .size    test_ukstsa32, .-test_ukstsa32

TEST_FUNC(test_uksub32)
    uksub32    a0, a0, a1
    ret
    .size    test_uksub32, .-test_uksub32

TEST_FUNC(test_umax32)
    umax32    a0, a0, a1
    ret
    .size    test_umax32, .-test_umax32

TEST_FUNC(test_umin32)
    umin32    a0, a0, a1
    ret
    .size    test_umin32, .-test_umin32

TEST_FUNC(test_uradd32)
    uradd32    a0, a0, a1
    ret
    .size    test_uradd32, .-test_uradd32

TEST_FUNC(test_urcras32)
    urcras32    a0, a0, a1
    ret
    .size    test_urcras32, .-test_urcras32

TEST_FUNC(test_urcrsa32)
    urcrsa32    a0, a0, a1
    ret
    .size    test_urcrsa32, .-test_urcrsa32

TEST_FUNC(test_urstas32)
    urstas32    a0, a0, a1
    ret
    .size    test_urstas32, .-test_urstas32

TEST_FUNC(test_urstsa32)
    urstsa32    a0, a0, a1
    ret
    .size    test_urstsa32, .-test_urstsa32

TEST_FUNC(test_ursub32)
    ursub32    a0, a0, a1
    ret
    .size    test_ursub32, .-test_ursub32
#endif

TEST_FUNC(test_smbb16)
    smbb16    a0, a0, a1
    ret
    .size   test_smbb16, .-test_smbb16

TEST_FUNC(test_smbt16)
    smbt16    a0, a0, a1
    ret
    .size   test_smbt16, .-test_smbt16

TEST_FUNC(test_smtt16)
    smtt16    a0, a0, a1
    ret
    .size   test_smtt16, .-test_smtt16

TEST_FUNC(test_kmda)
    kmda    a0, a0, a1
    ret
    .size   test_kmda, .-test_kmda

TEST_FUNC(test_kmxda)
    kmxda    a0, a0, a1
    ret
    .size   test_kmxda, .-test_kmxda

TEST_FUNC(test_smds)
    smds    a0, a0, a1
    ret
    .size   test_smds, .-test_smds

TEST_FUNC(test_smdrs)
    smdrs    a0, a0, a1
    ret
    .size   test_smdrs, .-test_smdrs

TEST_FUNC(test_smxds)
    smxds    a0, a0, a1
    ret
    .size   test_smxds, .-test_smxds

TEST_FUNC(test_kmabb)
    kmabb    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmabb, .-test_kmabb

TEST_FUNC(test_kmabt)
    kmabt    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmabt, .-test_kmabt

TEST_FUNC(test_kmatt)
    kmatt    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmatt, .-test_kmatt

TEST_FUNC(test_kmada)
    kmada    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmada, .-test_kmada

TEST_FUNC(test_kmaxda)
    kmaxda    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmaxda, .-test_kmaxda

TEST_FUNC(test_kmads)
    kmads    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmads, .-test_kmads

TEST_FUNC(test_kmadrs)
    kmadrs    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmadrs, .-test_kmadrs

TEST_FUNC(test_kmaxds)
    kmaxds    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmaxds, .-test_kmaxds

TEST_FUNC(test_kmsda)
    kmsda    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmsda, .-test_kmsda

TEST_FUNC(test_kmsxda)
    kmsxda    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_kmsxda, .-test_kmsxda

#ifdef RV32
TEST_FUNC(test_smal)
    smal    a0, a0, a2
    ret
    .size   test_smal, .-test_smal
#else
TEST_FUNC(test_smal)
    smal    a0, a0, a1
    ret
    .size   test_smal, .-test_smal
#endif

TEST_FUNC(test_sclip32_0)
    sclip32    a0, a0, 0x0
    ret
    .size   test_sclip32_0, .-test_sclip32_0

TEST_FUNC(test_sclip32_1)
    sclip32    a0, a0, 0x1
    ret
    .size   test_sclip32_1, .-test_sclip32_1

TEST_FUNC(test_sclip32_5)
    sclip32    a0, a0, 0x5
    ret
    .size   test_sclip32_5, .-test_sclip32_5

TEST_FUNC(test_sclip32_30)
    sclip32    a0, a0, 0x1e
    ret
    .size   test_sclip32_30, .-test_sclip32_30

TEST_FUNC(test_sclip32_31)
    sclip32    a0, a0, 0x1f
    ret
    .size   test_sclip32_31, .-test_sclip32_31

TEST_FUNC(test_uclip32_0)
    uclip32    a0, a0, 0x0
    ret
    .size   test_uclip32_0, .-test_uclip32_0

TEST_FUNC(test_uclip32_1)
    uclip32    a0, a0, 0x1
    ret
    .size   test_uclip32_1, .-test_uclip32_1

TEST_FUNC(test_uclip32_2)
    uclip32    a0, a0, 0x2
    ret
    .size   test_uclip32_2, .-test_uclip32_2

TEST_FUNC(test_uclip32_6)
    uclip32    a0, a0, 0x6
    ret
    .size   test_uclip32_6, .-test_uclip32_6

TEST_FUNC(test_uclip32_31)
    uclip32    a0, a0, 0x1f
    ret
    .size   test_uclip32_31, .-test_uclip32_31

TEST_FUNC(test_clrs32)
    clrs32    a0, a0
    ret
    .size   test_clrs32, .-test_clrs32

TEST_FUNC(test_clz32)
    clz32    a0, a0
    ret
    .size   test_clz32, .-test_clz32

TEST_FUNC(test_clo32)
    clo32    a0, a0
    ret
    .size   test_clo32, .-test_clo32

TEST_FUNC(test_pbsad)
    pbsad    a0, a0, a1
    ret
    .size   test_pbsad, .-test_pbsad

TEST_FUNC(test_pbsada)
    pbsada    a2, a0, a1
    mv        a0, a2
    ret
    .size   test_pbsada, .-test_pbsada

TEST_FUNC(test_smaqa)
    smaqa    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_smaqa, .-test_smaqa

TEST_FUNC(test_umaqa)
    umaqa    a2, a0, a1
    mv       a0, a2
    ret
    .size   test_umaqa, .-test_umaqa

TEST_FUNC(test_smaqa_su)
    smaqa.su    a2, a0, a1
    mv          a0, a2
    ret
    .size   test_smaqa_su, .-test_smaqa_su
#ifdef RV64
TEST_FUNC(test_add64)
    add64    a0, a0, a1
    ret
    .size   test_add64, .-test_add64

TEST_FUNC(test_radd64)
    radd64    a0, a0, a1
    ret
    .size   test_radd64, .-test_radd64

TEST_FUNC(test_uradd64)
    uradd64    a0, a0, a1
    ret
    .size   test_uradd64, .-test_uradd64

TEST_FUNC(test_kadd64)
    kadd64    a0, a0, a1
    ret
    .size   test_kadd64, .-test_kadd64

TEST_FUNC(test_ukadd64)
    ukadd64    a0, a0, a1
    ret
    .size   test_ukadd64, .-test_ukadd64

TEST_FUNC(test_sub64)
    sub64    a0, a0, a1
    ret
    .size   test_sub64, .-test_sub64

TEST_FUNC(test_rsub64)
    rsub64    a0, a0, a1
    ret
    .size   test_rsub64, .-test_rsub64

TEST_FUNC(test_ursub64)
    ursub64    a0, a0, a1
    ret
    .size   test_ursub64, .-test_ursub64
TEST_FUNC(test_ksub64)
    ksub64    a0, a0, a1
    ret
    .size   test_ksub64, .-test_ksub64

TEST_FUNC(test_uksub64)
    uksub64    a0, a0, a1
    ret
    .size   test_uksub64, .-test_uksub64
#else
TEST_FUNC(test_add64)
    add64    a0, a0, a2
    ret
    .size   test_add64, .-test_add64

TEST_FUNC(test_radd64)
    radd64    a0, a0, a2
    ret
    .size   test_radd64, .-test_radd64

TEST_FUNC(test_uradd64)
    uradd64    a0, a0, a2
    ret
    .size   test_uradd64, .-test_uradd64

TEST_FUNC(test_kadd64)
    kadd64    a0, a0, a2
    ret
    .size   test_kadd64, .-test_kadd64

TEST_FUNC(test_ukadd64)
    ukadd64    a0, a0, a2
    ret
    .size   test_ukadd64, .-test_ukadd64

TEST_FUNC(test_sub64)
    sub64    a0, a0, a2
    ret
    .size   test_sub64, .-test_sub64

TEST_FUNC(test_rsub64)
    rsub64    a0, a0, a2
    ret
    .size   test_rsub64, .-test_rsub64

TEST_FUNC(test_ursub64)
    ursub64    a0, a0, a2
    ret
    .size   test_ursub64, .-test_ursub64
TEST_FUNC(test_ksub64)
    ksub64    a0, a0, a2
    ret
    .size   test_ksub64, .-test_ksub64

TEST_FUNC(test_uksub64)
    uksub64    a0, a0, a2
    ret
    .size   test_uksub64, .-test_uksub64
#endif


#ifdef RV64
TEST_FUNC(test_smar64)
    smar64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smar64, .-test_smar64
TEST_FUNC(test_umar64)
    umar64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_umar64, .-test_umar64
TEST_FUNC(test_kmar64)
    kmar64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kmar64, .-test_kmar64

TEST_FUNC(test_ukmar64)
    ukmar64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_ukmar64, .-test_ukmar64

TEST_FUNC(test_smsr64)
    smsr64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smsr64, .-test_smsr64

TEST_FUNC(test_umsr64)
    umsr64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_umsr64, .-test_umsr64

TEST_FUNC(test_kmsr64)
    kmsr64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kmsr64, .-test_kmsr64

TEST_FUNC(test_ukmsr64)
    ukmsr64     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_ukmsr64, .-test_ukmsr64

TEST_FUNC(test_smalbb)
    smalbb     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smalbb, .-test_smalbb

TEST_FUNC(test_smalbt)
    smalbt     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smalbt, .-test_smalbt

TEST_FUNC(test_smaltt)
    smaltt     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smaltt, .-test_smaltt

TEST_FUNC(test_smalda)
    smalda     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smalda, .-test_smalda

TEST_FUNC(test_smalxda)
    smalxda     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smalxda, .-test_smalxda

TEST_FUNC(test_smalds)
    smalds     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smalds, .-test_smalds

TEST_FUNC(test_smaldrs)
    smaldrs     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smaldrs, .-test_smaldrs

TEST_FUNC(test_smalxds)
    smalxds     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smalxds, .-test_smalxds

TEST_FUNC(test_smslda)
    smslda     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smslda, .-test_smslda

TEST_FUNC(test_smslxda)
    smslxda     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_smslxda, .-test_smslxda

#else
TEST_FUNC(test_smar64)
    smar64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smar64, .-test_smar64
TEST_FUNC(test_umar64)
    umar64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_umar64, .-test_umar64

TEST_FUNC(test_kmar64)
    kmar64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_kmar64, .-test_kmar64

TEST_FUNC(test_ukmar64)
    ukmar64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_ukmar64, .-test_ukmar64

TEST_FUNC(test_smsr64)
    smsr64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smsr64, .-test_smsr64

TEST_FUNC(test_umsr64)
    umsr64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_umsr64, .-test_umsr64

TEST_FUNC(test_kmsr64)
    kmsr64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_kmsr64, .-test_kmsr64

TEST_FUNC(test_ukmsr64)
    ukmsr64     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_ukmsr64, .-test_ukmsr64

TEST_FUNC(test_smalbb)
    smalbb     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smalbb, .-test_smalbb

TEST_FUNC(test_smalbt)
    smalbt     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smalbt, .-test_smalbt

TEST_FUNC(test_smaltt)
    smaltt     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smaltt, .-test_smaltt

TEST_FUNC(test_smalda)
    smalda     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smalda, .-test_smalda

TEST_FUNC(test_smalxda)
    smalxda     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smalxda, .-test_smalxda

TEST_FUNC(test_smslda)
    smslda     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smslda, .-test_smslda

TEST_FUNC(test_smslxda)
    smslxda     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smslxda, .-test_smslxda

TEST_FUNC(test_smalds)
    smalds     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smalds, .-test_smalds

TEST_FUNC(test_smaldrs)
    smaldrs     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smaldrs, .-test_smaldrs

TEST_FUNC(test_smalxds)
    smalxds     a2, a0, a1
    mv         a0, a2
    mv         a1, a3
    ret
    .size   test_smalxds, .-test_smalxds

#endif

TEST_FUNC(test_kaddh)
    kaddh    a0, a0, a1
    ret
    .size   test_kaddh, .-test_kaddh

TEST_FUNC(test_ukaddh)
    ukaddh    a0, a0, a1
    ret
    .size   test_ukaddh, .-test_ukaddh

TEST_FUNC(test_ksubh)
    ksubh    a0, a0, a1
    ret
    .size   test_ksubh, .-test_ksubh

TEST_FUNC(test_uksubh)
    uksubh    a0, a0, a1
    ret
    .size   test_uksubh, .-test_uksubh

TEST_FUNC(test_khmbb)
    khmbb    a0, a0, a1
    ret
    .size   test_khmbb, .-test_khmbb

TEST_FUNC(test_khmbt)
    khmbt    a0, a0, a1
    ret
    .size   test_khmbt, .-test_khmbt

TEST_FUNC(test_khmtt)
    khmtt    a0, a0, a1
    ret
    .size   test_khmtt, .-test_khmtt

TEST_FUNC(test_kaddw)
    kaddw    a0, a0, a1
    ret
    .size   test_kaddw, .-test_kaddw

TEST_FUNC(test_ukaddw)
    ukaddw    a0, a0, a1
    ret
    .size   test_ukaddw, .-test_ukaddw

TEST_FUNC(test_ksubw)
    ksubw    a0, a0, a1
    ret
    .size   test_ksubw, .-test_ksubw

TEST_FUNC(test_uksubw)
    uksubw    a0, a0, a1
    ret
    .size   test_uksubw, .-test_uksubw

TEST_FUNC(test_kdmbb)
    kdmbb    a0, a0, a1
    ret
    .size   test_kdmbb, .-test_kdmbb

TEST_FUNC(test_kdmbt)
    kdmbt    a0, a0, a1
    ret
    .size   test_kdmbt, .-test_kdmbt

TEST_FUNC(test_kdmtt)
    kdmtt    a0, a0, a1
    ret
    .size   test_kdmtt, .-test_kdmtt

TEST_FUNC(test_kslraw)
    kslraw    a0, a0, a1
    ret
    .size   test_kslraw, .-test_kslraw

TEST_FUNC(test_kslraw_u)
    kslraw.u    a0, a0, a1
    ret
    .size   test_kslraw_u, .-test_kslraw_u

TEST_FUNC(test_ksllw)
    ksllw    a0, a0, a1
    ret
    .size   test_ksllw, .-test_ksllw

TEST_FUNC(test_kslliw_1)
    kslliw    a0, a0, 0x1
    ret
    .size   test_kslliw_1, .-test_kslliw_1

TEST_FUNC(test_kslliw_2)
    kslliw    a0, a0, 0x2
    ret
    .size   test_kslliw_2, .-test_kslliw_2

TEST_FUNC(test_kslliw_9)
    kslliw    a0, a0, 0x9
    ret
    .size   test_kslliw_9, .-test_kslliw_9

TEST_FUNC(test_kslliw_31)
    kslliw    a0, a0, 0x1f
    ret
    .size   test_kslliw_31, .-test_kslliw_31

TEST_FUNC(test_kdmabb)
    kdmabb     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kdmabb, .-test_kdmabb

TEST_FUNC(test_kdmabt)
    kdmabt     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kdmabt, .-test_kdmabt

TEST_FUNC(test_kdmatt)
    kdmatt     a2, a0, a1
    mv         a0, a2
    ret
    .size   test_kdmatt, .-test_kdmatt

TEST_FUNC(test_kabsw)
    kabsw     a0, a0
    ret
    .size   test_kabsw, .-test_kabsw

TEST_FUNC(test_raddw)
    raddw    a0, a0, a1
    ret
    .size   test_raddw, .-test_raddw

TEST_FUNC(test_uraddw)
    uraddw    a0, a0, a1
    ret
    .size   test_uraddw, .-test_uraddw

TEST_FUNC(test_rsubw)
    rsubw    a0, a0, a1
    ret
    .size   test_rsubw, .-test_rsubw

TEST_FUNC(test_ursubw)
    ursubw    a0, a0, a1
    ret
    .size   test_ursubw, .-test_ursubw

TEST_FUNC(test_maxw)
    maxw    a0, a0, a1
    ret
    .size   test_maxw, .-test_maxw

TEST_FUNC(test_minw)
    minw    a0, a0, a1
    ret
    .size   test_minw, .-test_minw

TEST_FUNC(test_mulr64)
    mulr64    a0, a0, a1
    ret
    .size   test_mulr64, .-test_mulr64

TEST_FUNC(test_mulsr64)
    mulsr64    a0, a0, a1
    ret
    .size   test_mulsr64, .-test_mulsr64

TEST_FUNC(test_ave)
    ave    a0, a0, a1
    ret
    .size   test_ave, .-test_ave

TEST_FUNC(test_sra_u)
    sra.u    a0, a0, a1
    ret
    .size   test_sra_u, .-test_sra_u

TEST_FUNC(test_srai_u_0)
    srai.u    a0, a0, 0x0
    ret
    .size   test_srai_u_0, .-test_srai_u_0

TEST_FUNC(test_srai_u_1)
    srai.u    a0, a0, 0x1
    ret
    .size   test_srai_u_1, .-test_srai_u_1

TEST_FUNC(test_srai_u_2)
    srai.u    a0, a0, 0x2
    ret
    .size   test_srai_u_2, .-test_srai_u_2

TEST_FUNC(test_srai_u_16)
    srai.u    a0, a0, 0x10
    ret
    .size   test_srai_u_16, .-test_srai_u_16

TEST_FUNC(test_srai_u_31)
    srai.u    a0, a0, 0x1f
    ret
    .size   test_srai_u_31, .-test_srai_u_31
#ifdef RV64
TEST_FUNC(test_srai_u_63)
    srai.u    a0, a0, 0x3f
    ret
    .size   test_srai_u_63, .-test_srai_u_63
#endif
TEST_FUNC(test_bitrev)
    bitrev    a0, a0, a1
    ret
    .size   test_bitrev, .-test_bitrev

TEST_FUNC(test_bitrevi_0)
    bitrevi    a0, a0, 0x0
    ret
    .size   test_bitrevi_0, .-test_bitrevi_0

TEST_FUNC(test_bitrevi_1)
    bitrevi    a0, a0, 0x1
    ret
    .size   test_bitrevi_1, .-test_bitrevi_1

TEST_FUNC(test_bitrevi_2)
    bitrevi    a0, a0, 0x2
    ret
    .size   test_bitrevi_2, .-test_bitrevi_2

TEST_FUNC(test_bitrevi_16)
    bitrevi    a0, a0, 0x10
    ret
    .size   test_bitrevi_16, .-test_bitrevi_16

TEST_FUNC(test_bitrevi_31)
    bitrevi    a0, a0, 0x1f
    ret
    .size   test_bitrevi_31, .-test_bitrevi_31
#ifdef RV64
TEST_FUNC(test_bitrevi_63)
    bitrevi    a0, a0, 0x3f
    ret
    .size   test_bitrevi_63, .-test_bitrevi_63
#endif

#ifdef RV64
TEST_FUNC(test_wext)
    wext    a0, a0, a1
    ret
    .size   test_wext, .-test_wext
#else
TEST_FUNC(test_wext)
    wext    a0, a0, a2
    ret
    .size   test_wext, .-test_wext
#endif

TEST_FUNC(test_wexti_2)
    wexti    a0, a0, 0x2
    ret
    .size   test_wexti_2, .-test_wexti_2

TEST_FUNC(test_wexti_4)
    wexti    a0, a0, 0x4
    ret
    .size   test_wexti_4, .-test_wexti_4

TEST_FUNC(test_wexti_8)
    wexti    a0, a0, 0x8
    ret
    .size   test_wexti_8, .-test_wexti_8

TEST_FUNC(test_wexti_31)
    wexti    a0, a0, 0x1f
    ret
    .size   test_wexti_31, .-test_wexti_31

TEST_FUNC(test_bpick)
    bpick    a3, a0, a1, a2
    mv       a0, a3
    ret
    .size   test_bpick, .-test_bpick

TEST_FUNC(test_maddr32)
    maddr32    a2, a0, a1
    mv         a0, a2
    ret
    .size   test_maddr32, .-test_maddr32

TEST_FUNC(test_insb_0)
    insb    a0, a1, 0x0
    ret
    .size   test_insb_0, .-test_insb_0

TEST_FUNC(test_insb_1)
    insb    a0, a1, 0x1
    ret
    .size   test_insb_1, .-test_insb_1

TEST_FUNC(test_insb_2)
    insb    a0, a1, 0x2
    ret
    .size   test_insb_2, .-test_insb_2

TEST_FUNC(test_insb_3)
    insb    a0, a1, 0x3
    ret
    .size   test_insb_3, .-test_insb_3
#ifdef RV64
TEST_FUNC(test_insb_4)
    insb    a0, a1, 0x4
    ret
    .size   test_insb_4, .-test_insb_4

TEST_FUNC(test_insb_5)
    insb    a0, a1, 0x5
    ret
    .size   test_insb_5, .-test_insb_5

TEST_FUNC(test_insb_6)
    insb    a0, a1, 0x6
    ret
    .size   test_insb_6, .-test_insb_6

TEST_FUNC(test_insb_7)
    insb    a0, a1, 0x7
    ret
    .size   test_insb_7, .-test_insb_7
#endif
