#include <string>

using namespace std;

string solution(string s) {
    for(int i = 0 ; i < s.size() ; ++i)
    {
        if(i == 0 && s[i] >= 'a' && s[i] <= 'z')
            s[i] += 'A'-'a';
        else if(i < (int)s.size()-1 && s[i] == ' ' && s[i+1] >= 'a' && s[i+1] <= 'z')
            s[i+1] += 'A'-'a';
        else if(i != 0 && s[i-1] != ' '&& s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 'a'-'A';          
    }
    return s;
}