#ifndef PROJECT_1_1_INSERTION_SORT_H
#define PROJECT_1_1_INSERTION_SORT_H

void insert(std::vector<int> &xs, int len) {
    for (int i = 1 ; i < len ; i++) {
        int val = xs[i];
        int cur = i;

        while (cur > 0 && xs[cur - 1] > val) {
            xs[cur] = xs[cur - 1];
            cur--;
        }

        xs[cur] = val;
    }
}

#endif //PROJECT_1_1_INSERTION_SORT_H
