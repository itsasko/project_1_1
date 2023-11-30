#include <iostream>
#include <chrono>
#include "tests.h"


int main() {
    using namespace std::chrono;
    auto start = std::chrono::steady_clock::now();
    quick_sort_testing();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();;

    std::cout << "Duration: " << duration << " nanoseconds" << std::endl;
    return 0;
}
