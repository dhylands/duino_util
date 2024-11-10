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
 *   @file   Crc8Test.cpp
 *
 *   @brief  Tests for functions in Crc8.cpp
 *
 ****************************************************************************/

#include <gtest/gtest.h>

#include "Crc8.h"
#include "Util.h"

uint8_t data[] = {0xca, 0xfc, 0x02, 0x00, 0x00};

//! Run some CRC's over some data.
TEST(CrcTest, CrcTest) {
    EXPECT_EQ(Crc8(0, LEN(data), data), 0xbf);

    uint8_t crc = 0;
    for (auto byte : data) {
        crc = Crc8(crc, byte);
    }
    EXPECT_EQ(crc, 0xbf);
}
