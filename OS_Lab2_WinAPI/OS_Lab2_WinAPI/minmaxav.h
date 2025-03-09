#pragma once
#include <windows.h>
#include <iostream>
#include <vector>

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
        Sleep(7);

        if (data->array[i] > data->max) {
            data->max = data->array[i];
        }
        Sleep(7);
    }
}

DWORD WINAPI MinMaxThread(LPVOID lpParam) {
    ThreadData* data = static_cast<ThreadData*>(lpParam);
    FindMinMax(data);
    std::cout << "Min: " << data->min << "\nMax: " << data->max << std::endl;
    return 0;
}

void CalculateAverage(ThreadData* data) {
    double sum = 0;
    for (int num : data->array) {
        sum += num;
        Sleep(12);
    }
    data->average = sum / data->array.size();
}

DWORD WINAPI AverageThread(LPVOID lpParam) {
    ThreadData* data = static_cast<ThreadData*>(lpParam);
    CalculateAverage(data);
    std::cout << "Average: " << data->average << std::endl;
    return 0;
}