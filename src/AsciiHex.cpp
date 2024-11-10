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
 *   @file   AsciiHex.cpp
 *
 *   @brief  Utilities for converting ASCII to binary.
 *
 ****************************************************************************/

#include "AsciiHex.h"

#include <cassert>
#include <cctype>

ByteBuffer AsciiHexToBinary(const char* str) {
    ByteBuffer result;
    uint8_t byte;
    bool high_nibble = true;
    while (*str != '\0') {
        if (*str == ' ') {
            str++;
            continue;
        }
        uint8_t nibble = 0;
        if (std::isdigit(*str)) {
            nibble = *str - '0';
        } else if (std::isxdigit(*str)) {
            nibble = toupper(*str) - 'A' + 10;
        } else {
            assert(!"Non-hex digit found");
        }
        if (high_nibble) {
            byte = nibble << 4;
        } else {
            byte |= nibble;
            result.push_back(byte);
        }
        high_nibble = !high_nibble;
        str++;
    }
    return result;
}
