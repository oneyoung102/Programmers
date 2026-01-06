#include <vector>

using namespace std;

int solution(vector<int> money) {
    if(money.size() == 1) return money[0];
    if(money.size() == 2) return max(money[0],money[1]);
    if(money.size() == 3) return max(money[0],max(money[1],money[2]));
    int answer = 0;
    for(int i = 0 ; i < 3 ; ++i)
    {
        vector<int> dp(money.size()-((i == 0) ? 1 : 0),0);
        dp[i] = money[i];
        for(int j = i+2 ; j < dp.size() ; ++j)
            dp[j] = max(dp[j-2],dp[max(j-3,0)])+money[j];
        answer = max(answer,max(dp[dp.size()-1],dp[dp.size()-2]));
    }
    return answer;
}