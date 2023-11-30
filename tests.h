#ifndef PROJECT_1_1_TESTS_H
#define PROJECT_1_1_TESTS_H

#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include "quick_sort.h"
#include "heap_sort.h"
#include "insertion_sort.h"
#include "radix_sort.h"

static std::vector<int> random_numbers_generator(int lower_bound, int upper_bound, std::string filename){

    using std::chrono::nanoseconds;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::ofstream fout(filename);

    std::uniform_int_distribution<int> dist_elements(lower_bound, upper_bound);
    std::uniform_int_distribution<int> dist_size(1, 1000);
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
static bool passed_test(std::vector<int> test){
    bool isPassed = true;
    for(int i = 1; i < test.size(); i++){
        if(test[i] < test[i-1]){
            isPassed = false;
        }
    }
    return isPassed;
}

void print_vector(std::vector<int> some_vector){
    for (auto i : some_vector) std::cout << i << " ";
    std::cout << std::endl;
}

void quick_sort_testing(){
    std::vector<int> test(random_numbers_generator(-1000, 1000, "C:\\Users\\oksa\\uni_projects\\project_1_1\\data\\quick_sort_numbers.txt"));
    std::vector<int>::iterator begin = test.begin();
    std::vector<int>::iterator end = test.end() - 1;

    quick_sort(begin, end);

    //if(passed_test(test)) std::cout << "PASSED" << std::endl;
    //else std::cout << "NOT PASSED" << std::endl;

}
void heap_sort_testing(){
    std::vector<int> test = random_numbers_generator(0, 1000, "C:\\Users\\oksa\\uni_projects\\project_1_1\\data\\heap_sort_numbers.txt");
    /*
    std::vector<int> test = {4, 99, 82, 64, 27, 1, 81, 71, 0, 25, 50, 6, 22, 88, 96, 31, 63, 20, 64, 99};
    //std::vector<int> test = {3, 9, 8, 2, 9, 7, 4, 5, 6, 4, 9, 4, 7, 7, 1, 4, 0, 7, 1, 0, 5, 5, 8, 2, 8, 0}; */
    std::vector<int>::iterator begin = test.begin();
    std::vector<int>::iterator end = test.end() - 1;

    /* print_vector(test);
    std::cout << std::endl << "printed" << std::endl; */

    heap_sort(begin, end);

    //print_vector(test);


    //std::cout << passed_test(test); */
    //if(passed_test(test)) std::cout << "PASSED" << std::endl;
    //else std::cout << "NOT PASSED" << std::endl;
}
void insertion_sort_testing(){
    std::vector<int> test = random_numbers_generator(-1000, 1000, "C:\\Users\\oksa\\uni_projects\\project_1_1\\data\\insertion_sort_numbers.txt");

    insertion_sort(test, test.size());


    //if(passed_test(test)) std::cout << "PASSED" << std::endl;
    //else std::cout << "NOT PASSED" << std::endl;
}

void radix_sort_testing(){
    std::vector<int> test = random_numbers_generator(0, 1000, "C:\\Users\\oksa\\uni_projects\\project_1_1\\data\\radix_sort_numbers.txt");

    radix_sort(test);

    //if(passed_test(test)) std::cout << "PASSED" << std::endl;
    //else std::cout << "NOT PASSED" << std::endl;
}

#endif //PROJECT_1_1_TESTS_H
