#include <vector>
#include <climits>

using namespace std;

int solution(int x, int y, int n) {
    vector<int> dp(y+1,INT_MAX);
    dp[x] = 0;
    for(int i = x+1 ; i <= y ; ++i)
    {
        if(i >= n && dp[i] > dp[i-n])
            dp[i] = dp[i-n]+1;
        if(i%2 == 0 && dp[i] > dp[i/2])
            dp[i] = dp[i/2]+1;
        if(i%3 == 0 && dp[i] > dp[i/3])
            dp[i] = dp[i/3]+1;
    }
    if(dp[y] == INT_MAX)
        return -1;
    return dp[y];
}