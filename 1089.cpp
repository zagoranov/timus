#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::string> vocabulary{"country",
"occupies",
"surface",
"covers",
"russia",
"largest",
"europe",
"part",
"about",
"world"};

std::string s_to_check {"the rushia is the larjest cauntry in the vorld. it ockupies abaut one-seventh of the earth's surfase. it kovers the eastern park of yurope and the northern park of asia."};

size_t compare(std::string& s1, const std::string& original) {
    size_t dif{0};
    if(s1.size() != original.size())
        return 2;
    for(size_t i = 0; i< original.size(); ++i) {
        if(s1[i] != original[i])
            ++dif;
    }
    return dif;
}

std::string find_word(std::string& word) {
    for(const std::string& s : vocabulary) {
        if(compare(word, s) == 1) {
            return s; 
        }
    }
    return "";
}


int main() {
    std::cout << "Text to check: \n" << s_to_check << '\n';
    std::string s_res, replacement;
    size_t ind{0}, found{0};
    while(ind < (s_to_check.size() - 1)) {
        //found = s_to_check.find(' ', ind);
        found = s_to_check.find_first_not_of("abcdefghijklmnopqrstuvwxyz", ind);
        if(found == std::string::npos)
            found = s_to_check.size() - 1;
        if(found - ind == 0) {
            s_res += s_to_check[found-1];
            ++ind;
            continue;
        }
        std::string target_word = s_to_check.substr(ind, found - ind);
        //std::cout << "Searching for replacement for: " << target_word << ", index: " << ind << ", found: " << found << '\n';
        std::string replacement = find_word(target_word);
        if(ind > 0)
            s_res += s_to_check[ind-1]; 
        if(replacement != "") {
            s_res += replacement;
            //std::cout << "Found replacement: " << replacement << "\n";
        }
        else 
            s_res += target_word;
        ind = (found + 1);
    }
    
    std::cout << "Result: \n" << s_res << '\n';
}
