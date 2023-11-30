#ifndef PROJECT_1_1_TESTS_H
#define PROJECT_1_1_TESTS_H

#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include "quick_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "radix_sort.h"

static std::vector<int> random_numbers_generator(int lower_bound, int upper_bound){
    using std::chrono::nanoseconds;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::ofstream fout("test_data.txt");

    std::uniform_int_distribution<int> dist_elements(lower_bound, upper_bound);
    std::uniform_int_distribution<int> dist_size(0, 1000);
    std::vector<int> random_test;
    int test_vector_size = dist_size(gen);
    int element;
    for(int i = 0; i < test_vector_size; i++){
        element = dist_elements(gen);
        random_test.push_back(element);
        fout << element << " ";
    }
    fout << std::endl;
    fout.close();
    return random_test;

}

void quick_sort_testing(){
    std::vector<int> test(random_numbers_generator(-1000, 1000));
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
    std::vector<int> test = random_numbers_generator(-1000, 1000);
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
    std::vector<int> test = random_numbers_generator(-1000, 1000);
    std::cout << "Insertion sort " << std::endl;
    std::cout << "Original vector of numbers: ";
    for (auto i : test) std::cout << i << " ";
    std::cout << std::endl;
    insertion_sort(test, test.size());
    std::cout << "Sorted : ";
    for (auto i : test) std::cout << i << " ";
}

void radix_sort_testing(){
    std::vector<int> test = random_numbers_generator(0, 1000);
    std::cout << "Radix sort " << std::endl;
    std::cout << "Original vector of numbers: ";
    for (auto i : test) std::cout << i << " ";
    std::cout << std::endl;
    radix_sort(test);
    std::cout << "Sorted : ";
    for (auto i : test) std::cout << i << " ";
}

#endif //PROJECT_1_1_TESTS_H
