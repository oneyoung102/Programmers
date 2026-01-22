#include <vector>

using namespace std;

int solution(vector<vector<int>> board)
{
    vector<vector<int>> dp(board.size(),vector<int>(board[0].size(),0));
    int answer = 0;
    for(int i = 0 ; i < board.size() ; ++i)
        for(int j =  0 ; j < board[0].size() ; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = board[i][j];
            else if(board[i][j] == 1)
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            answer = max(answer,dp[i][j]);
        }
    
    return answer*answer;
}