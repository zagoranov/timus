#include <iostream>
#include <string>
    
void no_spaces(std::string& s) {
    size_t ind{0};
    bool was_space{false};
    for(size_t i = 0; i < s.size(); ++i) {
        if(s[i] == ' ') {
            if(was_space) { ++ind; continue; }
            else { was_space = true; }
        }
        else {
            was_space = false;
        }
        if(ind > 0)
            std::swap(s[i], s[i-ind]);
    }
    s.resize(s.size() - ind);
}
