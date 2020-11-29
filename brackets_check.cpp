#include <string>
#include <map>
#include <iostream>

using namespace std;

map<char, char> brackets{{'(', ')'},{'{', '}'},{'[', ']'}};

bool checkNext(string& s, int pos) {
    if(s.empty())
        return true;
    if(pos >= s.size())
        return false;
    cout << "comparing " << s[pos] << " and " << s[pos+1] << endl;
    if( s[pos] == '(' || s[pos] == '{' || s[pos] == '[') {
        if(s[pos+1] == brackets[s[pos]]) {
            s = s.substr(0, pos) + s.substr(pos+2, s.size() - pos+2);
            cout << s << endl;
            return checkNext(s, pos-1);
        }
        else 
            return checkNext(s, pos+1);
    }
    else 
        return false;
}

int main() {  
    string s1{"{[]{()}}"};
    cout << s1 << endl << " - " << (checkNext(s1, 0) ? "Ok" : "Not Ok") << endl;

    string s2{"((()"};
    cout << s2 << " - " << (checkNext(s2, 0)?"Ok":"Not Ok") << endl;
    
    string s3{"[{}{})(]"};
    cout << s3 << " - " << (checkNext(s3, 0)?"Ok":"Not Ok") << endl;
    
    
}
