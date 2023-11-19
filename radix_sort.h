#ifndef PROJECT_1_1_RADIX_SORT_H
#define PROJECT_1_1_RADIX_SORT_H
static void counting_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){

}

static int find_max(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    int max_value = *iter_begin;
    iter_begin++;
    for(auto i = iter_begin; i <= iter_end; i++){
        if(*i > max_value) max_value = *i;
    }
    return max_value;
}

void radix_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    int max_value = find_max(iter_begin, iter_end), digits = -1;
    while(max_value > 1){
        digits ++;
        max_value / 10;
    }
}
#endif //PROJECT_1_1_RADIX_SORT_H
