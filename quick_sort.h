#ifndef PROJECT_1_1_QUICK_SORT_H
#define PROJECT_1_1_QUICK_SORT_H

void quick_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    if (iter_begin == iter_end) return;
    if (std::distance(iter_begin, iter_end) == 1){
        if(*iter_end > *iter_begin){
            int aux = *iter_begin;
            *iter_end = *iter_begin;
            *iter_begin = aux;}
        return;
    }
    std::vector<int>::iterator pivot = iter_begin;
    std::vector<int>::iterator i = iter_begin+1;
    std::vector<int>::iterator j = iter_end;
    while(i != j){
        if(*i > *pivot){
            if (*j <= *pivot) std::swap(*i, *j);
            else j++;
        }
        else{
            i++;
        }
    }
    quick_sort(iter_begin, i);
    quick_sort(j++, iter_end);
}

#endif //PROJECT_1_1_QUICK_SORT_H
