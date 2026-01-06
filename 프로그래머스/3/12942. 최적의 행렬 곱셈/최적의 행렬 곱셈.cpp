#include <vector>
#include <stack>
#include <climits>

using namespace std;

int solution(vector<vector<int>> matrix_sizes) {
    const int MSS = matrix_sizes.size();
    vector<vector<int>> dp(MSS,vector<int>(MSS,INT_MAX));
    for(int i = 0 ; i < MSS ; ++i)
        dp[i][i] = 0;
    for(int dist = 1 ; dist < MSS ; ++dist)
        for(int idx = 0 ; idx+dist < MSS ; ++idx)
        {
            const int left_row = matrix_sizes[idx][0], right_col = matrix_sizes[idx+dist][1];
            for(int slice = 0 ; slice < dist ; ++slice)
            {
                const int mid = matrix_sizes[idx+slice][1];
                const int mult_cost = dp[idx][idx+slice] + dp[idx+slice+1][idx+dist] + left_row*mid*right_col;
                dp[idx][idx+dist] = min(dp[idx][idx+dist],mult_cost);
            }
        }
    return dp[0][MSS-1];
}