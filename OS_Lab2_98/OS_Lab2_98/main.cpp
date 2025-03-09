#include <iostream>
#include "functions.h"
#include <vector>

#ifndef TESTING
int main() {
    int n;
    std::cout << "Enter array size: ";
    std::cin >> n;

    std::vector<double> arr(n);

    std::cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    double min_val, max_val, avg_val;

    find_min_max(arr, min_val, max_val);
    avg_val = compute_average(arr);

    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == min_val || arr[i] == max_val) {
            arr[i] = avg_val;
        }
    }

    std::cout << "Min: " << min_val << "\nMax: " << max_val << "\nAverage: " << avg_val << "\nResult: ";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    system("pause");
    return 0;
}
#endif