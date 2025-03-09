#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <future>
#include "functions.h"

void find_min_max(const std::vector<double>& arr, double& min_val, double& max_val, bool enable_sleep) {
    if (arr.empty()) return;
    min_val = arr[0];
    max_val = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min_val)
        {
            min_val = arr[i];
        }
        if (enable_sleep)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(7));
        }
        if (arr[i] > max_val)
        {
            max_val = arr[i];
        }
        if (enable_sleep)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(7));
        }
    }
}

double compute_average(const std::vector<double>& arr, bool enable_sleep) {
    double sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (enable_sleep)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(12));
        }
    }
    return arr.empty() ? 0 : sum / arr.size();
}