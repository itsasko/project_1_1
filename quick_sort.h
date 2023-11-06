#ifndef PROJECT_1_1_QUICK_SORT_H
#define PROJECT_1_1_QUICK_SORT_H

void quick_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    if (iter_begin == iter_end) return;
    if (std::distance(iter_begin, iter_end) == 1){
        if(*iter_end > *iter_begin){
        std::swap(*iter_begin, *iter_end);
        }
        return;
    }
    std::vector<int>::iterator pivot = iter_begin;
    std::vector<int>::iterator i = iter_begin+1; // left - less or equal
    std::vector<int>::iterator j = iter_end;
    while(i > j){ // Hoare
        if(*i > *pivot){
            i++;
        }
        if(*j <= *pivot){
            j--;
        }
        if(*i > *pivot && *j <= *pivot){
            std::swap(*i, *j);
            i++;
            j--;
        }
    }
    if (i > j) j++;
    std::swap(*i, *pivot);
    quick_sort(iter_begin, i);
    quick_sort(j++, iter_end);
}

#endif //PROJECT_1_1_QUICK_SORT_H
