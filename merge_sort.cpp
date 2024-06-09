#include <iostream>
#include <vector>

void merging(std::vector<int> &number_set_1, std::vector<int> &number_set_2){
    std::vector<int>::iterator i;
    std::vector<int>::iterator j;
    i = number_set_1.begin();
    j = number_set_2.begin();
    std::vector<int> number_set;
    if(i == number_set_1.end()){
        while (j != number_set_2.end()){
            number_set.push_back(*j);
            j++;
        }
    }
    if(j == number_set_2.end()){
        while (i != number_set_1.end()){
            number_set.push_back(*i);
            i++;
        }
    }
    if(*i > *j){
        number_set.push_back(*i);
    }
    else{
        number_set.push_back(*j);
    }
}

void merge_sort(std::vector<int> &number_set){
    std::vector<int> number_set_1;
    std::vector<int> number_set_2;
    number_set_1.begin() = number_set.begin();
    number_set_1.end() = number_set_1.begin() + number_set_1.size()/2;
    number_set_2.begin() = ++number_set_1.end();
    number_set_2.end() = number_set.end();
    merging(number_set_1, number_set_2);
    merge_sort(number_set_1);
    merge_sort(number_set_2);

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}