// [1,4,5,2,3,9,8,11,0] => "0-5,8-9,11"
// [1,4,3,2] => "1-4"
// [1,4] => "1,4"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // std::sort


void addString(std::string& res, int first, int before, int n) { 
    if(res != "")
        res += ",";
    if(n > 0) {
        res += std::to_string(first) + "-" + std::to_string(before);
    }
else 
    res += std::to_string(before);
}

std::string getRanges(std::vector<int> v) {
    std::string res;
    std::sort(v.begin(), v.end());
    
    int before = -1, first, n = 0;
    auto it = v.begin(), resIt = it;
    while(it != v.end()) {
        if(before == -1) { before = *it; ++it; continue; }
        if(before + 1 == *it) {
            if(n == 0) {
                first = before;
            }
            ++n;
        }
        else {
            addString(res, first, before, n);
             n = 0;
        }
        before = *it;
        ++it;
    }
    addString(res, first, before, n);    
    return res;
}
             
        
int main() {  
  std::vector<int> v{1,4,5,2,3,9,8,11,0};
  std::cout << getRanges(v) <<"\n";
}
