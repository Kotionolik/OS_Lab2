#include <gtest/gtest.h>
#include "functions.h"
#include <vector>

TEST(MinMaxTest, Basic) {
    std::vector<double> arr = { 5, 3, 8, 1, 6 };
    double min_val, max_val;
    find_min_max(arr, min_val, max_val, false);
    EXPECT_EQ(min_val, 1);
    EXPECT_EQ(max_val, 8);
}

TEST(AverageTest, Basic) {
    std::vector<double> arr = { 1, 2, 3, 4 };
    double avg = compute_average(arr, false);
    EXPECT_DOUBLE_EQ(avg, 2.5);
}

TEST(IntegrationTest, FullProcess) {
    std::vector<double> arr = { 1, 2, 3, 4 };
    double min_val, max_val;
    find_min_max(arr, min_val, max_val, false);
    double avg = compute_average(arr, false);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == min_val || arr[i] == max_val)
        {
            arr[i] = avg;
        }
    }
    std::vector<double> expected = { 2.5, 2, 3, 2.5 };
    EXPECT_EQ(arr, expected);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}