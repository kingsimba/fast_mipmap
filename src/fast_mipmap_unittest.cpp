#include "gtest/gtest.h"
#include "fast_mipmap.h"

TEST(FastMipmap, basic)
{
    u8 data[25] = {
        1,  2,  3,  4,  5,  //
        4,  5,  6,  7,  8,  //
        9,  10, 11, 12, 13, //
        14, 15, 16, 17, 18, //
        19, 20, 21, 22, 23,
    };

    auto img = reduceImage(data, 5, 5);
    ASSERT_EQ(img->width(), 2);
    ASSERT_EQ(img->height(), 2);
    EXPECT_EQ(img->pixelAt(0, 0), 1);
    EXPECT_EQ(img->pixelAt(1, 0), 3);
    EXPECT_EQ(img->pixelAt(0, 1), 9);
    EXPECT_EQ(img->pixelAt(1, 1), 11);
}
