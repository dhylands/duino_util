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
 *   @file   strncpy_s.cpp
 *
 *   @brief   An implementation of strncpy_s.
 *   @details See https://en.cppreference.com/w/c/string/byte/strncpy
 *
 ****************************************************************************/

#include <cerrno>

#include "duino_util/Util.h"

int strncpy_s(
    char* dst,        //!< [out] Place to store the copied string.
    char const* src,  //!< [in] String to copy.
    size_t maxLen     //!< [in] Size of `dst`.
) {
    size_t bytesCopied = 0;
    while ((*dst++ = *src++) != '\0') {
        if (++bytesCopied >= maxLen) {
            // We just copied a non-null into the last character position. This means that the
            // source string along with the teminating null won't fit in the destination. So
            // we truncate the destination string.
            *--dst = '\0';
            return ERANGE;
        }
    }
    return 0;
}
