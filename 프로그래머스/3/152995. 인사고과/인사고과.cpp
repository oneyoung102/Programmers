#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> wanho_score = scores[0];
    sort(scores.begin(),scores.end(),[](const vector<int>& x, const vector<int>& y){
        if(x[0] > y[0])
            return true;
        return x[0] == y[0] && x[1] > y[1];
    });
    vector<vector<int>> standing; standing.push_back(scores[0]);
    int prev_max_score = 0, curr_max_score = scores[0][1];
    for(int i = 1 ; i < scores.size() ; ++i)
    {
        if(scores[i-1][0] != scores[i][0])
        {
            prev_max_score = max(prev_max_score,curr_max_score);
            curr_max_score = scores[i][1];
        }
        if(prev_max_score > scores[i][1])
            continue;
        standing.push_back(scores[i]);
    }
    sort(standing.begin(),standing.end(),[](const vector<int>& x, const vector<int>& y){
        return x[0]+x[1] > y[0]+y[1];
    });
    int rank = 1;
    for(int i = 0 ; i < standing.size() ; ++i)
    {
        if(i != 0 && standing[i-1][0]+standing[i-1][1] != standing[i][0]+standing[i][1])
            rank = i+1;
        if(standing[i][0] == wanho_score[0] && standing[i][1] == wanho_score[1])
            return rank;
    }
    return -1;
}