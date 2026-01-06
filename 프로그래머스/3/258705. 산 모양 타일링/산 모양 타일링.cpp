#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 1e4+7;
    vector<int> dp(2*n+2,0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2 ; i < dp.size() ; ++i)
        if(i%2 == 1) //정방향 삼각형
            dp[i] = ((long long)dp[i-2] + dp[i-1])%MOD; // i번째 삼각형
        else//역삼각형
        {
            const int top_pos = (i-2)/2;
            if(tops[top_pos] == 0)
                dp[i] = ((long long)dp[i-2] + dp[i-1])%MOD;
            else
                dp[i] = ((long long)dp[i-2] + 2ll*dp[i-1])%MOD;
        }
    return dp.back();
}