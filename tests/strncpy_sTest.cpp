/****************************************************************************
 *
 *   @copyright Copyright (c) 2024 Dave Hylands     <dhylands@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the MIT License version as described in the
 *   LICENSE file in the root of this repository.
 *
 ****************************************************************************/
/**
 *   @file   strncpy_sTest.cpp
 *
 *   @brief  Tests for strncpy_s function
 *
 ****************************************************************************/

#include <gtest/gtest.h>

#include "duino_util/Util.h"

TEST(strncpy_sTest, ZeroDestTest) {
    char dst[16];

    memset(dst, 0xee, sizeof(dst));
    strncpy_s(dst, "12345", 1);
    EXPECT_EQ(dst[0], '\0');
    EXPECT_EQ(dst[1], '\xEE');
}

TEST(strncpy_sTest, TruncTest) {
    char dst[16];

    memset(dst, 0xee, sizeof(dst));
    strncpy_s(dst, "12345", 4);
    EXPECT_STREQ(dst, "123");
    EXPECT_EQ(dst[4], '\xEE');
}

TEST(strncpy_sTest, NormalTest) {
    char dst[16];

    memset(dst, 0xee, sizeof(dst));
    strncpy_s(dst, "12345", sizeof(dst));
    EXPECT_STREQ(dst, "12345");
    EXPECT_EQ(dst[6], '\xEE');
}
