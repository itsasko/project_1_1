#ifndef PROJECT_1_1_INSERTION_SORT_H
#define PROJECT_1_1_INSERTION_SORT_H



void insertion_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    std::vector<int>::iterator i = iter_begin;
    std::vector<int>::iterator max_el = iter_begin;
    for (i; i <= iter_end; i++){
        if(*i > *max_el) *max_el = *i;
    }
    std::swap(*max_el, *iter_end);
    if(iter_begin != iter_end) insertion_sort(iter_begin, --iter_end);
    return;
}

#endif //PROJECT_1_1_INSERTION_SORT_H
