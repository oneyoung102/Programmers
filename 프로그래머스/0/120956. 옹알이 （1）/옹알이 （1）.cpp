#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(auto& it : babbling)
    {
        int pos = 0;
        while(pos < it.size())
        {
            if(it.substr(pos,3) == "aya")
                pos+=3;
            else if(it.substr(pos,3) == "woo")
                pos+=3;
            else if(it.substr(pos,2) == "ye")
                pos+=2;
            else if(it.substr(pos,2) == "ma")
                pos+=2;
            else
                break;
        }   
        if(pos == it.size())
            answer++;
    }
    return answer;
}