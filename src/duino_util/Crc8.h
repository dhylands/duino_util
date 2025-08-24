/****************************************************************************
 *
 *   Copyright (c) 2006 Dave Hylands     <dhylands@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License version 2 as
 *   published by the Free Software Foundation.
 *
 *   Alternatively, this software may be distributed under the terms of BSD
 *   license.
 *
 *   See README and COPYING for more details.
 *
 ****************************************************************************/
/**
 *
 *   @file   Crc8.h
 *
 *   @brief  This file contains the definition of the CRC-8 algorithim
 *           used by SMBus
 *
 ****************************************************************************/

#pragma once

#include <cstddef>
#include <cinttypes>

//! Calculates the CRC-8 used as part of SMBus.
//! CRC-8 is defined to be x^8 + x^2 + x + 1
//! @returns the updated CRC.
uint8_t Crc8(
    uint8_t crc,  //!< [in] CRC accumulated so far.
    uint8_t data  //!< [in] Byte to accumulate into the CRC.
);

//! Calculates the CRC-8 used as part of SMBus over a block of memory.
//! @returns the updated CRC.
uint8_t Crc8(
    uint8_t crc,         //!< [in] CRC accumulated so far.
    size_t len,          //!< [in] Amount of data to accumulate CRC over.
    uint8_t const* data  //!< [in] Data to accumulate
);
