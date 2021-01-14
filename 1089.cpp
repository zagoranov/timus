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

std::string text_to_check {"the rushia is the larjest cauntry in the vorld. it ockupies abaut one-seventh of the earth's surfase. it kovers the eastern park of yurope and the northern park of asia."};

size_t compareWords(std::string& s1, const std::string& original) {
    size_t dif{0};
    if(s1.size() != original.size())
        return 2;
    for(size_t i = 0; i< original.size(); ++i) {
        if(s1[i] != original[i])
            ++dif;
    }
    return dif;
}

std::string findWord(std::string& word) {
    for(const std::string& s : vocabulary) {
        if(compareWords(word, s) == 1) {
            return s; 
        }
    }
    return "";
}

std::string checkText(const std::string& s_to_check) {
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
        std::cout << "Searching for replacement for: " << target_word << ", index: " << ind << ", found: " << found << '\n';
        if(ind > 0)
            s_res += s_to_check[ind-1]; 
        std::string replacement = findWord(target_word);
        if(replacement != "") {
            s_res += replacement;
            std::cout << "Found replacement: " << replacement << "\n";
        }
        else 
            s_res += target_word;
        ind = (found + 1);
    }    return s_res;
}


int main() {
    std::cout << "Text to check: \n" << text_to_check << "\n\n";
    std::string res = checkText(text_to_check);
    std::cout << "\nResult: \n" << res << '\n';
}
