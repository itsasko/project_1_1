#ifndef PROJECT_1_1_RADIX_SORT_H
#define PROJECT_1_1_RADIX_SORT_H

#define iterator1 std::vector<std::pair<std::vector<int>::iterator,int>>::iterator

static std::vector<std::vector<std::pair<iterator1, int>>> counting_sort(iterator1  iter_begin, iterator1 iter_end, int max_num){
    std::vector<std::vector<std::pair<iterator1, int>>> box;
    for (int i = 0; i < max_num; i++){
        std::vector<std::pair<iterator1, int>> aux;
        box.push_back(aux);
    }
    for (auto j = iter_begin; j <= iter_end; j++){
        std::vector<int>::iterator aux_iter = (*j).first;
        int aux_index = *aux_iter;
        box[aux_index].push_back(*j); // make_pair also doesn't work
    }
    return box;
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
    int aux = max_value;
    while (aux > 1) {
        digits++;
        aux /= 10;
    } // number of digits in the biggest number is obtained

}

#endif //PROJECT_1_1_RADIX_SORT_H
