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
 *   @file   millis.cpp
 *
 *   @brief  Provides non-Arduino implementations of millis
 *
 ****************************************************************************/

#include "duino_util/millis.h"

#if defined(ARDUINO)

// millis is defined in the Arduino Framework

#elif defined(LIB_PICO_TIME)

#include "pico/stdlib.h"
#include "pico/time.h"

uint32_t millis() {
    return to_ms_since_boot(get_absolute_time());
}

#else

uint32_t millis() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}

#endif
