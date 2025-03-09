#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

struct ThreadData {
    std::vector<int> array;
    int min = 0;
    int max = 0;
    double average = 0.0;
};

void FindMinMax(ThreadData* data) {
    if (data->array.empty()) return;

    data->min = data->array[0];
    data->max = data->array[0];

    for (size_t i = 1; i < data->array.size(); ++i) {
        if (data->array[i] < data->min) {
            data->min = data->array[i];
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(7));

        if (data->array[i] > data->max) {
            data->max = data->array[i];
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
    }
}

void MinMaxThread(ThreadData* data) {
    FindMinMax(data);
    std::cout << "Min: " << data->min << "\nMax: " << data->max << std::endl;
}

void CalculateAverage(ThreadData* data) {
    double sum = 0;
    for (int num : data->array) {
        sum += num;
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }
    data->average = sum / data->array.size();
}

void AverageThread(ThreadData* data) {
    CalculateAverage(data);
    std::cout << "Average: " << data->average << std::endl;
}