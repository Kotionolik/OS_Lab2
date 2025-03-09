#include <iostream>
#include <vector>
#include <cassert>
#include "functions.h"

void test_min_max() {
    std::vector<double> arr;
    double min_val, max_val;

    arr = { 5.0, 3.0, 8.0, 1.0, 6.0 };
    find_min_max(arr, min_val, max_val);
    assert(min_val == 1.0);
    assert(max_val == 8.0);
    std::cout << "[OK] test_min_max (basic)\n";

    arr = { 5.0, 5.0, 5.0 };
    find_min_max(arr, min_val, max_val);
    assert(min_val == 5.0 && max_val == 5.0);
    std::cout << "[OK] test_min_max (same values)\n";
}

void test_average() {
    std::vector<double> arr;

    arr = { 1.0, 2.0, 3.0, 4.0 };
    double avg = compute_average(arr);
    assert(avg == 2.5);
    std::cout << "[OK] test_average (basic)\n";

    arr.clear();
    avg = compute_average(arr);
    assert(avg == 0.0);
    std::cout << "[OK] test_average (empty array)\n";
}

void test_replace() {
    std::vector<double> arr = { 1.0, 2.0, 3.0, 4.0 };
    double min_val, max_val;

    find_min_max(arr, min_val, max_val);
    double avg = compute_average(arr);

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == min_val || arr[i] == max_val) {
            arr[i] = avg;
        }
    }
    std::vector<double> expected = { 2.5, 2.0, 3.0, 2.5 };
    assert(arr == expected);
    std::cout << "[OK] test_replace\n";
}

int main() {
    test_min_max();
    test_average();
    test_replace();

    std::cout << "\nAll tests passed!\n";
    system("pause");
    return 0;
}