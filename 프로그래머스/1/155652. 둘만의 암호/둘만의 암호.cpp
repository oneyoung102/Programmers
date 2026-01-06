#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> alphabet;
    for(int letter = 'a' ; letter <= 'z' ; ++letter)
        if(skip.find(letter) == string::npos)
            alphabet.push_back(letter);
    for(const auto& it : s)
    {
        auto pos = find(alphabet.begin(),alphabet.end(),it);
        answer+= alphabet[(pos-alphabet.begin()+index)%alphabet.size()];
    }
    return answer;
}