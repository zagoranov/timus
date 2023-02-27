// Finding the longest palindromic substring
// https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <string>
#include <utility>
	
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        pair<size_t, size_t> max_pal{0, 1};
        for(size_t i = 0; i < s.length(); ++i) {
            int l = GetPalindrom(s.substr(i, s.length() - i ));
            if(l > max_pal.second) {
                max_pal.first = i;
                max_pal.second = l;
            }
        }
        return s.substr(max_pal.first, max_pal.second);
    }

    int GetPalindrom(std::string s) {
        int len = 1;
        std::string q{s[0]};
        for(size_t i = 1; i < s.length()/2 + 1; ++i) {
            string ss = s.substr(i, q.length());
            if(q == ss) 
                len = q.length() * 2;
            ss = s.substr(i+1, q.length());
            if(q == ss) 
                len = q.length() * 2 + 1;
            q = s[i] + q;
        }
        return len;
    }
};


int main() {
  Solution s;
  string str{"asfgfsr"};
    std::cout << s.longestPalindrome( str );
}
