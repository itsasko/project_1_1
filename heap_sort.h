#ifndef PROJECT_1_1_HEAP_SORT_H
#define PROJECT_1_1_HEAP_SORT_H

// left child = 2*i + 1
// right child = 2*i + 2
// parent = (j-1)/2

static std::vector<int>* heap = new std::vector<int>;

void building_a_heap(std::vector<int>::iterator &iter_begin, std::vector<int>::iterator &iter_end){

    int i_index, parent_index;
    for (std::vector<int>::iterator j = iter_begin; j != iter_end; j++){
        heap->push_back(*j);
        i_index = heap->size() - 1 ;
        parent_index = (i_index - 1) / 2;
        std::vector<int>::iterator i = heap->begin() + i_index;
        std::vector<int>::iterator parent = heap->begin() + parent_index;
        if(*i > *parent){
            std::swap(*i, *parent);
            std::swap(i, parent);
        }
    }
    iter_begin = heap->begin();
    iter_end = heap->end() - 1;
    std::cout << *heap->begin() << std::endl;

}

void heap_sort(std::vector<int>::iterator iter_begin, std::vector<int>::iterator iter_end){


}
#endif //PROJECT_1_1_HEAP_SORT_H
