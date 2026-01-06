#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    const int mod = 1e9+7;
    vector<int> dp(n+1,0);
    dp[0] = 1;
    for(int i = 0 ; i < money.size() ; ++i)
    {
        const int m = money[i];
        for(int j = 0 ; j < n && m+j <= n ; ++j)
            dp[m+j] = (dp[m+j]+dp[j])%mod;
    }
    return dp[n];
}