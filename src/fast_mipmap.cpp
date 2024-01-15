#include "fast_mipmap.h"
#include <cstdint>
#include <iostream>
#include <algorithm>

typedef uint8_t u8;

std::shared_ptr<ImageU8> reduceImage(const uint8_t* data, int width, int height)
{
    const int stride = width;
    width = width >> 1;
    height = height >> 1;
    auto smallerImg = std::make_shared<ImageU8>(width, height);
    u8* dest = smallerImg->mutablePixels();
    const u8* src = data;
    const u8* srcEnd = src + stride * height * 2;
    u8 pixel4[4];
    while (src != srcEnd)
    {
        const u8* line = src;
        const u8* lineEnd = src + (width << 1);
        while (line != lineEnd)
        {
            pixel4[0] = line[0];
            pixel4[1] = line[1];
            pixel4[2] = line[stride];
            pixel4[3] = line[stride + 1];
            *dest++ = *std::min_element(pixel4, pixel4 + 4);
            line += 2;
        }
        src += stride << 1;
    }

    return smallerImg;
}
