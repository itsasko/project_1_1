#ifndef PROJECT_1_1_RADIX_SORT_H
#define PROJECT_1_1_RADIX_SORT_H


static std::vector<int> counting_sort(std::vector<int> &xs, int digit_to_sort, int max_digits){
    std::vector<int> pos(10, 0);
    std::vector<int> sorted(xs.size(), 0);
    for(auto i : xs) {
        int aux = i, digit;
        for(int j = 1; j <= max_digits; j++){
            if(j == digit_to_sort){
                digit = aux%10;
                break;
            }
            aux /= 10;
        }
        pos[digit] += 1;
    }
    for(int i = 1; i < pos.size(); i++) pos[i] += pos[i - 1];
    for(int i = xs.size()-1; i >= 0; i--){
        int aux = xs[i], digit;
        for(int j = 1; j <= max_digits; j++){
            if(j == digit_to_sort) {
                digit = aux%10;
                break;
            }
            aux /= 10;
        }
        pos[digit] --;
        sorted[pos[digit]] = xs[i];
    }
    return sorted;
}

static int find_max(std::vector<int> &xs){
    int max_value = xs[0];
    for(auto i  : xs){
        if(i > max_value) max_value = i;
    }
    return max_value;
}

void radix_sort(std::vector<int> &xs) {
    int max_value = find_max(xs), digits = 0;
    std::vector<int> rs;
    int aux = max_value;
    while (aux >= 1) {
        digits++;
        aux /= 10;
    } // number of digits in the biggest number is obtained
    rs = counting_sort(xs, 1, digits);
    for(int i = 2; i <= digits; i++){
        rs = counting_sort(rs, i, digits);
    }
    xs = rs;

}

#endif //PROJECT_1_1_RADIX_SORT_H
