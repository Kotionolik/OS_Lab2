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

    std::thread min_max_thread(MinMaxThread, &data);
    std::thread average_thread(AverageThread, &data);

    min_max_thread.join();
    average_thread.join();

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