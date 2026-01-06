#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    const int M = board.size(), N = board[0].size();
    vector<vector<int>> delta(M+1,vector<int>(N+1,0));
    for(const auto& s : skill)
    {
        const int d = s[5]*((s[0] == 1) ? -1 : 1);
        delta[s[1]][s[2]] += d;
        delta[s[1]][s[4]+1] -= d;
        delta[s[3]+1][s[2]] -= d;
        delta[s[3]+1][s[4]+1] += d;
    }
    vector<int> col_delta(N,0);
    int answer = 0;
    for(int i = 0 ; i < M ; ++i)
    {
        int d = 0;
        for(int j = 0 ; j < N ; ++j)
        {
            col_delta[j] += delta[i][j];
            d += col_delta[j];      
            if(board[i][j]+d > 0)
                ++answer;
        }
    }
    return answer;
}