#ifndef PROJECT_1_1_HEAP_SORT_H
#define PROJECT_1_1_HEAP_SORT_H

// left child = 2*i + 1
// right child = 2*i + 2
// parent = (j-1)/2

void building_a_heap(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    std::vector<int> heap;
    int i_index, parent_index;
    for (std::vector<int>::iterator j = iter_begin; j <= iter_end; j++){
        heap.push_back(*j);
        i_index = heap.size() - 1;
        parent_index = (i_index - 1) / 2;
        std::vector<int>::iterator i = heap.begin() + i_index;
        std::vector<int>::iterator parent = heap.begin() + parent_index;
        while(*i > *parent){
            std::swap(*i, *parent);
            std::swap(i_index, parent_index);
            std::swap(i, parent);
            parent_index = (i_index - 1) / 2;
            parent = heap.begin() + parent_index;
            if(i == heap.begin()) break;
        }
    }
    std::vector<int>::iterator i_1;
    for (i_1 = heap.begin(); i_1 != heap.end(); i_1++) {
        *iter_begin = *i_1;
        iter_begin++;
    }
}

void fixing_a_heap(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    int i_index = 0, left_child_index = 1, right_child_index = 2;
    int heap_size = std::distance(iter_begin, iter_end);
    std::vector<int>::iterator i = iter_begin;
    std::vector<int>::iterator right_child = iter_begin + right_child_index;
    std::vector<int>::iterator left_child = iter_begin + left_child_index;
    while (i <= iter_end){
        if(*i < *left_child && left_child_index <= heap_size){
            std::swap(*i, *left_child);
            std::swap(i, left_child);
            i_index = left_child_index;
            if (*left_child < *right_child && right_child_index <= heap_size){
                std::swap(*left_child, *right_child);
                std::swap(left_child, right_child);
            }
            right_child_index = 2 * i_index + 2;
            right_child = iter_begin + right_child_index;
            left_child_index = 2 * i_index + 1;
            left_child = iter_begin + left_child_index;

        }
        else if(*i < *right_child && right_child_index <= heap_size){
            std::swap(*i, *right_child);
            std::swap(i, right_child);
            i_index = right_child_index;
            right_child_index = 2 * i_index + 2;
            right_child = iter_begin + right_child_index;
        }
        else break;
    }
}

void heap_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){
    building_a_heap(iter_begin, iter_end);
    for (std::vector<int>::iterator j = iter_end; j >= iter_begin; j--){
        for (auto k = iter_begin; k <= iter_end; k++) std::cout << *k << " ";
        std::cout << std::endl;
        //std::cout << *iter_begin << std::endl;
        std::swap(*iter_end, *iter_begin);
        fixing_a_heap(iter_begin, --iter_end);
    }
}
#endif //PROJECT_1_1_HEAP_SORT_H
