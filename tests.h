#ifndef PROJECT_1_1_TESTS_H
#define PROJECT_1_1_TESTS_H

#include <vector>
#include <algorithm>
#include "quick_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "radix_sort.h"

void quick_sort_testing(){
    std::vector<int> test{500, 446538, 31413, 232842, 385, 269, 113989};
    std::vector<int>::iterator begin = test.begin();
    std::vector<int>::iterator end = test.end() - 1;
    std::cout << "Quick sort " << std::endl;
    std::cout << "Original vector of numbers: ";
    for (auto i : test) std::cout << i << " ";
    std::cout << std::endl;
    quick_sort(begin, end);
    std::cout << "Sorted : ";
    for (auto i : test) std::cout << i << " ";
}
void heap_sort_testing(){
    std::vector<int> test{500, 446538, 31413, 232842, 385, 269, 113989};
    std::vector<int>::iterator begin = test.begin();
    std::vector<int>::iterator end = test.end() - 1;
    std::cout << "Heap sort " << std::endl;
    std::cout << "Original vector of numbers: ";
    for (auto i : test) std::cout << i << " ";
    std::cout << std::endl;
    heap_sort(begin, end);
    std::cout << "Sorted : ";
    for (auto i : test) std::cout << i << " ";
}
void insertion_sort_testing(){
    std::vector<int> test{500, 446538, 31413, 232842, 385, 269, 113989};
    std::cout << "Insertion sort " << std::endl;
    std::cout << "Original vector of numbers: ";
    for (auto i : test) std::cout << i << " ";
    std::cout << std::endl;
    insertion_sort(test, test.size());
    std::cout << "Sorted : ";
    for (auto i : test) std::cout << i << " ";
}

void radix_sort_testing(){
    std::vector<int> test{500, 446538, 31413, 232842, 385, 269, 113989};
    std::cout << "Radix sort " << std::endl;
    std::cout << "Original vector of numbers: ";
    for (auto i : test) std::cout << i << " ";
    std::cout << std::endl;
    radix_sort(test);
    std::cout << "Sorted : ";
    for (auto i : test) std::cout << i << " ";
}

#endif //PROJECT_1_1_TESTS_H
