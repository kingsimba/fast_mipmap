#include "gtest/gtest.h"
#include "neon_min.h"
#include <vector>

TEST(Main, findSmallest)
{
    uint8_t data[16] = {
        3, 8, 4, 2, 3, 10, 255, 254, //
        1, 2, 3, 4, 5, 6,  8,   7,   //
    };
    findSmallest(data);

    std::vector<u8> result;
    result.assign(data, data + 8);

    EXPECT_EQ(result, std::vector<u8>({ 3, 2, 3, 254, 1, 3, 5, 7 }));
}
