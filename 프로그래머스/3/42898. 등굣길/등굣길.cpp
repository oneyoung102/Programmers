#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int mod = 1e9+7;
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = 1;
    for(const auto& p : puddles)
        dp[p[0]-1][p[1]-1] = -1;
    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j)
        {
            if(dp[i][j] == -1)
                continue;
            if(i >= 1 && dp[i-1][j] != -1)
                dp[i][j] = (dp[i-1][j]+(long long)dp[i][j])%mod;
            if(j >= 1 && dp[i][j-1] != -1)
                dp[i][j] = (dp[i][j-1]+(long long)dp[i][j])%mod;
        }
    return dp[m-1][n-1];
}