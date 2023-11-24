#ifndef PROJECT_1_1_RADIX_SORT_H
#define PROJECT_1_1_RADIX_SORT_H


static std::vector<int> counting_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end, int digit_to_sort, int max_digits){
    std::vector<int> pos;
    std::vector<int> sorted;
    for(int i = 0; i < 11; i++) pos.push_back(0);
    for(int i = 0; i < std::distance(iter_begin, iter_end); i++) sorted.push_back(0);
    for(auto i = iter_begin; i <= iter_end; i++){
        int aux = *i, digit;
        for(int j = 1; j <= max_digits; j++){
            if(j = digit_to_sort) digit = aux%10;
            aux /= 10;
        }
        pos[digit] += 1;
    }
    for(int i = 1; i < pos.size(); i++) pos[i] += pos[i - 1];
    for(auto i = iter_end; i >= iter_begin; i-- ){
        int aux = *i, digit;
        for(int j = 0; j < max_digits; j++){
            if(j = digit_to_sort) digit = aux%10;
            aux /= 10;
        }
        pos[digit] --;
        sorted[pos[digit]] = *i;
    }
    return pos;
}

static int find_max(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    int max_value = *iter_begin;
    iter_begin++;
    for(auto i = iter_begin; i <= iter_end; i++){
        if(*i > max_value) max_value = *i;
    }
    return max_value;
}

void radix_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end) {
    int max_value = find_max(iter_begin, iter_end), digits = -1;
    std::vector<int> rs;
    int aux = max_value;
    while (aux > 1) {
        digits++;
        aux /= 10;
    } // number of digits in the biggest number is obtained
    int size = std::distance(iter_begin, iter_end);
    for(int i = 1; i <= digits; i++){
        for(int j = 0; j < size; j++){
            rs = counting_sort(iter_begin, iter_end, j, digits);
        }
    }
    iter_begin = rs.begin();
    iter_end = rs.begin() + size;
}

#endif //PROJECT_1_1_RADIX_SORT_H
