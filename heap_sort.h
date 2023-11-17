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
        i_index = heap.size() - 1 ;
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

void heap_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){

}
#endif //PROJECT_1_1_HEAP_SORT_H
