#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

extern int excavate(int);


int solution(vector<int> depth, int money) {
    const int w = depth.size();
    
    vector<vector<int>> dp(w,vector<int>(w,20000000));
    vector<vector<int>> pick(w,vector<int>(w,0));
    
    for (int len = 1; len <= w; ++len)
        for (int left = 0; left <= w - len; ++left)
        {
            int right = left + len - 1;

            if (len == 1)
            {
                dp[left][right] = depth[left];
                pick[left][right] = left;
                continue;
            }
            for (int i = left; i <= right; ++i)
            {
                const int left_cost = (i > left) ? dp[left][i - 1] : 0;
                const int right_cost = (i < right) ? dp[i + 1][right] : 0;
                const int cost = depth[i] + max(left_cost,right_cost);
                if(cost < dp[left][right])
                {
                    dp[left][right] = cost;
                    pick[left][right] = i;
                }
            }
        }

    
    int left = 0, right = w-1;
    while(left <= right)
    {
        const int mid = pick[left][right];

        const int result = excavate(mid+1);
        if(result == 0)
            return mid+1;
        else if(result == -1)
            right = mid-1;
        else
            left = mid+1;
    }
    return 0;
}