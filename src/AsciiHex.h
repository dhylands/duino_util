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
 *   @file   AsciiHex.h
 *
 *   @brief  Class whih performs a sequence of actions on specfied intervals.
 *
 ****************************************************************************/

#pragma once

#include <cstdint>
#include <vector>

//! Convenience aliases
//! @{
using ByteBuffer = std::vector<uint8_t>;
//! @}

//! @brief Converts an ASCII string containing hexadecimal digits into binary data.
//! @details Ignnores spaces.
//! @example
//!     @code
//!     auto bytes = AsciiHexToBinary("12 34");
//!     @endcode
//      `bytes[0] will contain 0x12 and bytes[1] will contain 0x34.
//! @returns a uint8_t vector containing the bytes parsed from the string.
ByteBuffer AsciiHexToBinary(char const* str  //!< [in] String to convert.
);
