#include <set>
#include <vector>
#include <climits>
#include <utility>

using namespace std;

int solution(int N, int number) {
    vector<int> dp(N*number+1,INT_MAX); dp[0] = 0;

    auto cmp = [&dp](const int a, const int b) {
        return dp[a] < dp[b];
    };
    multiset<int, decltype(cmp)> sp(cmp);

    int n = N;
    for(int i = 1 ; n < dp.size() ; ++i)
    {
        dp[n] = i;
        sp.insert(n); 
        n = n*10+N;  
    }

    auto ele_insert = [&sp,&dp,N](int n, int num) -> bool {
        if(n < dp.size() && n > 0 && dp[n] > num)
        {
            dp[n] = num;
            sp.insert(n);
            return false;
        };
        return false;
    };
    for(auto it = sp.begin() ; it != sp.end() ; ++it)
    {
        const int n1 = *it;
        for(auto itr = it ; itr != sp.end() ; ++itr)
        {
            const int n2 = *itr;
            const int count_sum = dp[n1]+dp[n2]; 
            if(count_sum > 8)
                break;
            if(ele_insert(n1+n2,count_sum) && n1+n2 == number) return dp[number];
            if(ele_insert(n1*n2,count_sum) && n1*n2 == number) return dp[number];
            if(ele_insert(n1/n2,count_sum) && n1/n2 == number) return dp[number];
            if(ele_insert(n2/n1,count_sum) && n2/n1 == number) return dp[number];
            if(ele_insert(n1-n2,count_sum) && n1-n2 == number) return dp[number];
            if(ele_insert(n2-n1,count_sum) && n2-n1 == number) return dp[number];
        }
    }
    if(dp[number] <= 8)
        return dp[number];
    return -1;
}