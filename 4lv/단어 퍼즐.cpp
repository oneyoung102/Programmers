#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<string> strs, string t)
{
    const int max_count = 20001;
    vector<int> dp(t.size(),max_count);
    set<string> dict;
    for(const string& str : strs)
        dict.insert(str);
    
    for(int i = 0 ; i < t.size() ; ++i)
        for(int j = 0 ; j < 5 && i >= j ; ++j)
            if(dict.find(t.substr(i-j,j+1)) != dict.end())
                dp[i] = min(dp[i],((i == j) ? 0 : dp[i-j-1])+1);

    if(dp.back() == max_count)
        return -1;
    return dp.back();
}
