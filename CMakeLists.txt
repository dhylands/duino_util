add_library(duino_util STATIC
    src/AsciiHex.cpp
    src/Crc8.cpp
    src/millis.cpp
    src/strncpy_s.cpp
    src/TimedActionSequence.cpp
)

target_include_directories(duino_util PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(duino_util pico_stdlib)
