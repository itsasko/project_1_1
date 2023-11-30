#include <iostream>
#include <chrono>
#include "tests.h"

long long time_measurement_q(){
    using namespace std::chrono;
    auto start = std::chrono::steady_clock::now();
    quick_sort_testing();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}
long long time_measurement_h(){
    using namespace std::chrono;
    auto start = std::chrono::steady_clock::now();
    heap_sort_testing();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}
long long time_measurement_r(){
    using namespace std::chrono;
    auto start = std::chrono::steady_clock::now();
    radix_sort_testing();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}
long long time_measurement_i(){
    using namespace std::chrono;
    auto start = std::chrono::steady_clock::now();
    insertion_sort_testing();
    auto end = std::chrono::steady_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    return duration;
}
void data_collecting(){
    std::ofstream fq_out("time_taken_q.txt");
    std::ofstream fh_out("time_taken_h.txt");
    std::ofstream fi_out("time_taken_i.txt");
    std::ofstream fr_out("time_taken_r.txt");

    for(int i = 0; i < 100; i++){
        fq_out << time_measurement_q() << std::endl;
        fh_out << time_measurement_h() << std::endl;
        fi_out << time_measurement_i() << std::endl;
        fr_out << time_measurement_r() << std::endl;
    }

    fq_out.close();
    fh_out.close();
    fi_out.close();
    fr_out.close();
}

int main() {
    data_collecting();
    //std::cout << "Duration: " << time_measurement_q() << " nanoseconds" << std::endl;
    return 0;
}
