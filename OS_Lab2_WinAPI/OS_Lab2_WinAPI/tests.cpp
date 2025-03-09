#include <gtest/gtest.h>
#include "minmaxav.h"

TEST(ThreadDataTest, FindMinMax) {
    ThreadData data;
    data.array = { 5, 3, 8, 1, 6 };
    FindMinMax(&data);
    EXPECT_EQ(data.min, 1);
    EXPECT_EQ(data.max, 8);
}

TEST(ThreadDataTest, CalculateAverage) {
    ThreadData data;
    data.array = { 1, 2, 3, 4, 5 };
    CalculateAverage(&data);
    EXPECT_DOUBLE_EQ(data.average, 3.0);
}

TEST(ThreadDataTest, ReplaceMinMax) {
    ThreadData data;
    data.array = { 1, 2, 1, 5, 5 };
    data.min = 1;
    data.max = 5;
    data.average = 3.0;

    for (auto& num : data.array) {
        if (num == data.min || num == data.max) {
            num = static_cast<int>(data.average);
        }
    }

    std::vector<int> expected = { 3, 2, 3, 3, 3 };
    EXPECT_EQ(data.array, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}