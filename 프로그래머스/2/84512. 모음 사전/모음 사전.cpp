#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    for(char& c : word)
        if(c == 'A') c = '1';
        else if(c == 'E') c = '2';
        else if(c == 'I') c = '3';
        else if(c == 'O') c = '4';
        else if(c == 'U') c = '5';
    int answer = 0;
    string s = "";
    while(s != word)
    {
        if(s.size() != 5)
            s += '1';
        else
        {
            s.back() += 1;
            while(s.back() == '6')
            {
                s.pop_back();
                s.back() += 1;
            }
        }
        ++answer; 
    }
    return answer;
}