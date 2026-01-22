#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    unsigned int index_end = 0;
    map<string,unsigned int> index;
    for(char c = 'A' ; c <= 'Z' ; ++c)
    {
        string s = "";
        s += c;
        index[s] = ++index_end;
    }
    
    vector<int> answer;
    int i = 0;
    while(i < msg.size())
    {
        string exp = "";
        int j = i;
        while(j < msg.size())
        {
            exp += msg[j];
            if(index[exp] == 0)
            {
                index[exp] = ++index_end;
                exp.pop_back();
                break;
            }
            ++j;
        }
        answer.push_back(index[exp]);
        i = j;
    }
    return answer;
}