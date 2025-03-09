#include "minmaxav.h"

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;
    while (size < 0)
    {
        std::cout << "Error: array size should be at least zero. Enter again: ";
        std::cin >> size;
    }

    std::vector<int> arr(size);
    std::cout << "Enter array elements:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    ThreadData data;
    data.array = arr;

    HANDLE hMinMax = CreateThread(nullptr, 0, MinMaxThread, &data, 0, nullptr);
    HANDLE hAverage = CreateThread(nullptr, 0, AverageThread, &data, 0, nullptr);

    if (!hMinMax || !hAverage) {
        std::cerr << "Error creating threads!" << std::endl;
        return 1;
    }

    WaitForSingleObject(hMinMax, INFINITE);
    WaitForSingleObject(hAverage, INFINITE);

    CloseHandle(hMinMax);
    CloseHandle(hAverage);

    int avg = static_cast<int>(data.average);
    for (auto& num : data.array) {
        if (num == data.min || num == data.max) {
            num = avg;
        }
    }

    std::cout << "Modified array: ";
    for (int num : data.array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    system("pause");

    return 0;
}