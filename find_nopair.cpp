// Finding no-pair element in array

#include <vector>
#include <iostream>
    
int main() {
    std::vector<int> ints { 9, 1, 2, 7, 5, 1, 7, 9, 2};
    int j = 0;
    for(int  i : ints) {
        j ^= i;
    }    
    std::cout << j;
}
