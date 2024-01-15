
#pragma once

#include <cstdint>

typedef uint8_t u8;

#if defined(__aarch64__)
#include <arm_neon.h>
#else
#include <algorithm>
#include <cstring>

/// <summary>
/// Simulate NEON with C functions
/// </summary>
struct uint8x8_t {
    u8 data[8];
};

inline uint8x8_t vld1_u8(const u8* data) {
    uint8x8_t rtn;
    memcpy(&rtn.data, data, 8);
    return rtn;
}

inline void vst1_u8(uint8_t* ptr, uint8x8_t val) { memcpy(ptr, &val.data, 8); }

inline uint8x8_t vpmin_u8(uint8x8_t l, uint8x8_t r) {
    uint8x8_t rtn;
    int n = 0;
    for (int i = 0; i < 8; i += 2) {
        rtn.data[n++] = std::min(r.data[i], r.data[i + 1]);
    }

    for (int i = 0; i < 8; i += 2) {
        rtn.data[n++] = std::min(l.data[i], l.data[i + 1]);
    }

    return rtn;
}
#endif

void findSmallest(uint8_t data[16]) {
    uint8x8_t data1 = vld1_u8(data + 8);
    uint8x8_t data2 = vld1_u8(data);
    data1 = vpmin_u8(data1, data2);
    vst1_u8(data, data1);
}
