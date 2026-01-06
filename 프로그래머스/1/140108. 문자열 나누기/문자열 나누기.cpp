#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 1;
    int start = 0;
    int total = 0;
    for(int i = start ; i < s.size() ; i++)
    {
        if(s[start]==s[i])
            total++;
        else
            total--;
        printf("1");
        if(total==0&&i!=s.size()-1)
        {
            answer++;
            start = i+1;
            total = 0;
            printf(",");
        }            
    }
    return answer;
}