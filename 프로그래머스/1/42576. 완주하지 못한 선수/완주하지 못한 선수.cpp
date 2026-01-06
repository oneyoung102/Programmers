#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(),participant.end());
    sort(completion.begin(),completion.end());
    completion.push_back("1");
    for(int i = 0 ; i < participant.size() ; i++)
        if(completion[i]!=participant[i])
            return participant[i];
}