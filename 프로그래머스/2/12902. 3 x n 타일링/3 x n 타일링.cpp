#include <vector>

using namespace std;

int solution(int n) {
    const int mod = 1e9+7;
    if(n%2 == 1)
        return 0;
    vector<long long> dp(n/2+1,0);
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 2 ; i <= n/2 ; ++i)
        dp[i] = (dp[i-1]*4 - dp[i-2]+mod)%mod;
    return dp[n/2];
}