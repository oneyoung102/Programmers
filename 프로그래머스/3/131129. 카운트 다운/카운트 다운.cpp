#include <vector>
#include <climits>

using namespace std;

vector<int> solution(int target) {
    vector<vector<int>> dp(target+1,{INT_MAX,-1});
    for (int i = 1 ; i <= target; ++i)
    {
        if (i <= 20) dp[i] = {1, 1};
        else if(i == 50) dp[i] = {1, 1};
        else if (i % 2 == 0 && i <= 40) dp[i] = {1, 0};
        else if (i % 3 == 0 && i <= 60) dp[i] = {1, 0};
        else
            for (int j = 1 ; j <= 60 && j < i; ++j)
            {
                const int count_sum = dp[j][0] + dp[i-j][0];
                const int single_sum = dp[j][1] + dp[i-j][1];

                if (count_sum < dp[i][0])
                    dp[i] = {count_sum, single_sum};
                else if (count_sum == dp[i][0] && single_sum > dp[i][1])
                    dp[i] = {count_sum, single_sum};
            }
    }
    return dp[target];
}