#include <vector>
#include <array>

using namespace std;

int solution(vector<vector<int>> land)
{
    array<int,4> dp = {0,};
    
    for(const auto& l : land)
    {
        array<int,4> dp_sub = dp;
        for(int i = 0 ; i < 4 ; ++i)
        {
            int except_max = 0;
            for(int j = 0 ; j < 4 ; ++j)
                if(j != i)
                    except_max = max(except_max,dp[j]);
            dp_sub[i] = max(dp[i],except_max+l[i]);
        }
        dp = dp_sub;
    }
    int answer = 0;
    for(int i = 0 ; i < 4 ; ++i)
        answer = max(answer,dp[i]);
    return answer;
}