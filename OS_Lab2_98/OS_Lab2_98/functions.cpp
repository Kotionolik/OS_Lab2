#include "functions.h"
#include <vector>
#include <ctime>

void delay_ms(unsigned int ms) {
    clock_t start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < ms);
}

void find_min_max(const std::vector<double>& arr, double& min_val, double& max_val) {
    if (arr.empty()) return;
    min_val = arr[0];
    max_val = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < min_val) min_val = arr[i];
        delay_ms(7);
        if (arr[i] > max_val) max_val = arr[i];
        delay_ms(7);
    }
}

double compute_average(const std::vector<double>& arr) {
    double sum = 0;
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        delay_ms(12);
    }
    return arr.empty() ? 0 : sum / arr.size();
}