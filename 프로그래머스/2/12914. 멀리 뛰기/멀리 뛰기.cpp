#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 1;
    const int mod = 1234567;
    vector<int> dp(n-1,1);
    if(n >= 2) ++answer;
    if(n >= 3) ++answer;
    for(int i = 2 ; i < n-1 ; ++i)
    {
        dp[i] = (dp[i-1]+dp[i-2])%mod;
        answer = (answer + dp[i])%mod;
    }
    return answer;
}