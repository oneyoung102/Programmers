#include <vector>

using namespace std;

int solution(vector<int> sticker)
{
    if(sticker.size() == 1)
        return sticker[0];
    if(sticker.size() == 2)
        return max(sticker[0],sticker[1]);
    
    int answer = 0;
    for(int i = 0 ; i < 3 ; ++i)
    {
        const int n = (int)sticker.size() + ((i == 0) ? -1 : 0);
        vector<int> dp(n,0);
        dp[i] = sticker[i];
        for(int j = i+2 ; j < n ; ++j)
        {
            const int prev = (dp[j-2] == 0) ? dp[j-3] : dp[j-2]; 
            dp[j] = max(dp[j-1],prev+sticker[j]);
        }
        for(int i = 1 ; i <= 3 && n >= i ; ++i)
            answer = max(answer,dp[n-i]);
    }
    return answer;
}