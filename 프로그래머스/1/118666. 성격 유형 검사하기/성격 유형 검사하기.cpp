#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> type;
    type['R'] = 0;
    type['T'] = 0;
    type['C'] = 0;
    type['F'] = 0;
    type['J'] = 0;
    type['M'] = 0;
    type['A'] = 0;
    type['N'] = 0;
    
    for(int i = 0 ; i < survey.size() ; i++)
    {
        if(choices[i]>4)
            type[survey[i][1]]+=choices[i]-4;
        else if(choices[i]<4)
            type[survey[i][0]]+=4-choices[i];
    }
    if(type['R']>=type['T'])
        answer+='R';
    else
        answer+='T';
    if(type['C']>=type['F'])
        answer+='C';
    else
        answer+='F';
    if(type['J']>=type['M'])
        answer+='J';
    else
        answer+='M';
    if(type['A']>=type['N'])
        answer+='A';
    else
        answer+='N';
    return answer;
}