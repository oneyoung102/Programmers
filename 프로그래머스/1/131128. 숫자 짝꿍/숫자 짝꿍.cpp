#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<vector<int>> counting(2, vector(10,0));
    for(int i = 0 ; i < X.size() ; i++)
        counting[0][X[i]-'0']++;
    for(int i = 0 ; i < Y.size() ; i++)
        counting[1][Y[i]-'0']++;
    for(int i = 0 ; i<10 ; i++)
    {
        int common_num = min(counting[0][i], counting[1][i]);
            for(int j = 0 ; j < common_num ; j++)
                answer+=i+'0';
    }
    sort(answer.begin(),answer.end(),greater());
    if(answer == "")
        return "-1";
    else if(answer[0] == '0')
        return "0";
    else 
        return answer;
}