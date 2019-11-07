//----------------------------------------------------------------------------
//   The confidential and proprietary information contained in this file may
//   only be used by a person authorised under and to the extent permitted
//   by a subsisting licensing agreement from ARM Limited or its affiliates.
//
//          (C) COPYRIGHT [2018] ARM Limited or its affiliates.
//              ALL RIGHTS RESERVED
//
//   This entire notice must be reproduced on all copies of this file
//   and copies of this file may only be made by a person if such person is
//   permitted to do so under the terms of a subsisting license agreement
//   from ARM Limited or its affiliates.
//----------------------------------------------------------------------------


#ifndef __COMMON_H__
#define __COMMON_H__
/*
 * Apical(ARM) V4L2 test application 2016
 *
 * This is ARM internal development purpose SW tool running on JUNO.
 */

#define ISP_RAW_PLANES 2

/* feature definitions */
#define ARM_V4L2_TEST_HAS_META  0
#define ARM_V4L2_TEST_HAS_RAW   0

#define CONVERT_RAW_4_TO_2      1
#define TIFF_USE_EXIF           1

/* custom v4l2 formats */
#define ISP_V4L2_PIX_FMT_META           v4l2_fourcc('M', 'E', 'T', 'A') /* META */
#define ISP_V4L2_PIX_FMT_ARGB2101010    v4l2_fourcc('B', 'A', '3', '0') /* ARGB2101010 */
#define ISP_V4L2_PIX_FMT_RGB24			v4l2_fourcc('B', 'G', 'R', '0')
//#define V4L2_PIX_FMT_NV21    		v4l2_fourcc('N', 'V', '2', '1') /* 12  Y/CrCb 4:2:0  */


/* custom v4l2 controls */
#define ISP_V4L2_CID_ISP_V4L2_CLASS     (0x00f00000 | 1)
#define ISP_V4L2_CID_BASE               (0x00f00000 | 0xf000)
#define ISP_V4L2_CID_TEST_PATTERN       (ISP_V4L2_CID_BASE + 0)
#define ISP_V4L2_CID_TEST_PATTERN_TYPE  (ISP_V4L2_CID_BASE + 1)
#define ISP_V4L2_CID_AF_REFOCUS         (ISP_V4L2_CID_BASE + 2)
#define ISP_V4L2_CID_SENSOR_PRESET       (ISP_V4L2_CID_BASE + 3)

/* stream types */

enum {
    ARM_V4L2_TEST_STREAM_FR = 0,
#if ARM_V4L2_TEST_HAS_META
    ARM_V4L2_TEST_STREAM_META,
#endif
#if ARM_V4L2_TEST_HAS_RAW   /* RAW stream should be at the bottom of the list */
    ARM_V4L2_TEST_STREAM_RAW,
#endif
    ARM_V4L2_TEST_STREAM_MAX
};


/* bit flag macros */

enum {
    STREAM_FLAG_FR      = 1 << ARM_V4L2_TEST_STREAM_FR,
#if ARM_V4L2_TEST_HAS_META
    STREAM_FLAG_META    = 1 << ARM_V4L2_TEST_STREAM_META,
#endif
#if ARM_V4L2_TEST_HAS_RAW
    STREAM_FLAG_RAW     = 1 << ARM_V4L2_TEST_STREAM_RAW,
#endif
    STREAM_FLAG_MAX     = 1 << ARM_V4L2_TEST_STREAM_MAX
};

const static uint32_t STREAM_FLAG_PREVIEW
    = STREAM_FLAG_FR
#if ARM_V4L2_TEST_HAS_META
    | STREAM_FLAG_META
#endif
;

const static uint32_t STREAM_FLAG_CAPTURE
    = STREAM_FLAG_FR
#if ARM_V4L2_TEST_HAS_META
    | STREAM_FLAG_META
#endif
#if ARM_V4L2_TEST_HAS_RAW
    | STREAM_FLAG_RAW
#endif
;

#define ID_TO_FLAG(id)  (1 << id)

#endif
