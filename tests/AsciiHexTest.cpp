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
 *   @file   AsciiHexTest.cpp
 *
 *   @brief  Tests for functions in AsciiHex.cpp
 *
 ****************************************************************************/

#include <gtest/gtest.h>

#include "duino_util/AsciiHex.h"

TEST(AsciiHexTest, NoDataTest) {
    auto bin = AsciiHexToBinary("");
    EXPECT_EQ(bin.size(), 0);
}

TEST(AsciiHexTest, OneByteTest) {
    auto bin = AsciiHexToBinary("34");
    EXPECT_EQ(bin.size(), 1);
    EXPECT_EQ(bin[0], 0x34);
}

TEST(AsciiHexTest, TwoBytesWithSpaceTest) {
    auto bin = AsciiHexToBinary("ab cd");
    EXPECT_EQ(bin.size(), 2);
    EXPECT_EQ(bin[0], 0xab);
    EXPECT_EQ(bin[1], 0xcd);
}

TEST(AsciiHexTest, TwoBytesNoSpaceTest) {
    auto bin = AsciiHexToBinary("abcd");
    EXPECT_EQ(bin.size(), 2);
    EXPECT_EQ(bin[0], 0xab);
    EXPECT_EQ(bin[1], 0xcd);
}

TEST(AsciiHexTest, TwoBytesExtraSpaceTest) {
    auto bin = AsciiHexToBinary(" a b c d ");
    EXPECT_EQ(bin.size(), 2);
    EXPECT_EQ(bin[0], 0xab);
    EXPECT_EQ(bin[1], 0xcd);
}

TEST(AsciiHexTest, TwoBytesOddDigitsTest) {
    auto bin = AsciiHexToBinary(" ab c ");
    EXPECT_EQ(bin.size(), 1);
    EXPECT_EQ(bin[0], 0xab);
}

TEST(AsciiHexDeathTest, InvalidHex) {
    ASSERT_DEATH(
        { auto bin = AsciiHexToBinary(" ab x "); }, "Assertion `!\"Non-hex digit found\"' failed.");
}
