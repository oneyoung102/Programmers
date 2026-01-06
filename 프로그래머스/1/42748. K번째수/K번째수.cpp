#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int k=0;k<commands.size();k++)
    {
        vector<int> dummy(array.begin()+commands[k][0]-1,array.begin()+commands[k][1]);
        sort(dummy.begin(),dummy.end());
        answer.push_back(dummy[commands[k][2]-1]);
    }
    
    return answer;
}