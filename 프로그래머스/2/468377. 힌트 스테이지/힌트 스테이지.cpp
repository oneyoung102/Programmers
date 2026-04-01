#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    int min_total_cost = INT_MAX;
    const size_t n = cost.size(), k = hint[0].size()-1;
    const unsigned int end = pow(2,n-1);
    for(unsigned int bit = 0 ; bit < end ; ++bit)
    { 
        int total_cost = 0;
        vector<unsigned int> hint_count(n,0);
        for(unsigned int idx = 0, bin = 1 ; idx < n-1 ; ++idx, bin *= 2)
            if((bit&bin) == bin)
            {
                total_cost += hint[idx][0];
                for(size_t i = 1 ; i <= k ; ++i)
                    ++hint_count[hint[idx][i]-1];
            }
        for(size_t i = 0 ; i < n ; ++i)
            total_cost += cost[i][min(hint_count[i],(unsigned int)n-1)];
        min_total_cost = min(min_total_cost,total_cost);
    }
    return min_total_cost;
}