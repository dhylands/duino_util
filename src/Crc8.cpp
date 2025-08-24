/****************************************************************************
 *
 *   @copytight Copyright (c) 2006 Dave Hylands     <dhylands@gmail.com>
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
 *   @file   Crc8.cpp
 *
 *   @brief  This file contains the definition of the CRC-8 algorithim
 *           used by SMBus
 *
 *
 *****************************************************************************/

#include "duino_util/Crc8.h"

uint8_t Crc8(uint8_t crc, uint8_t data) {
    crc ^= data;

    for (size_t i = 0; i < 8; i++) {
        if ((crc & 0x80) != 0) {
            crc <<= 1;
            crc ^= 0x07;
        } else {
            crc <<= 1;
        }
    }
    return crc;
}

uint8_t Crc8(uint8_t crc, size_t len, uint8_t const* data) {
    while (len > 0) {
        crc = Crc8(crc, *data++);
        len--;
    }
    return crc;
}
