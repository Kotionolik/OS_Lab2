#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <future>

void find_min_max(const std::vector<double>& arr, double& min_val, double& max_val, bool enable_sleep = true);

double compute_average(const std::vector<double>& arr, bool enable_sleep = true);