#include <iostream>
#include <vector>
#include <thread>
#include "functions.h"
#include <chrono>
#include <future>

#ifndef TESTING
int main() {
    int n;
    std::cout << "Enter amount of elements:\n";
    std::cin >> n;
    std::vector<double> arr(n);
    std::cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    double min_val, max_val;
    double average_val;

    std::promise<void> min_max_promise;
    std::future<void> min_max_future = min_max_promise.get_future();
    std::thread min_max_thread([&] {
        find_min_max(arr, min_val, max_val);
        std::cout << "Min: " << min_val << "\nMax: " << max_val << std::endl;
        min_max_promise.set_value();
        });

    std::promise<double> average_promise;
    std::future<double> average_future = average_promise.get_future();
    std::thread average_thread([&] {
        double avg = compute_average(arr);
        std::cout << "Average: " << avg << std::endl;
        average_promise.set_value(avg);
        });

    min_max_thread.join();
    average_thread.join();
    min_max_future.get();
    average_val = average_future.get();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == min_val || arr[i] == max_val)
        {
            arr[i] = average_val;
        }
    }

    std::cout << "Result: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    system("pause");

    return 0;
}
#endif