#include <vector>
#include <iostream>

int main() {
    std::vector<int> a = { 1,6,2,1,5,6,2 };

    const size_t sz = a.size();
    int max_cnt = 1;
    int max_i = 0;
    size_t i = 0, j = 0;
    do {
        int prev = i;
        int cnt = 1;
        for(j = i+1; j < sz; ++j) {
            if(a[prev] <= a[j]) {
                ++cnt;
                prev = j;
            }
            else
                break;
        }
        if(cnt > max_cnt) {
            max_cnt = cnt;
            max_i = i;
        }
        i = j;
    } while (++i < sz);

    std::cout << "Longest incremental sequence starts at: " << max_i << " and its length is: " << max_cnt;
}
