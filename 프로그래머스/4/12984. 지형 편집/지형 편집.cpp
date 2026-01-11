#include <vector>
#include <climits>

using namespace std;

long long get_cost(vector<vector<int>>& land, long long P, long long Q, int height)
{
    long long cost = 0;
    for(const auto& lan : land)
        for(const int l : lan)
        {
            if(l >= height)
                cost += (l-height)*Q;
            else
                cost += (height-l)*P;
        }
    return cost;
}
long long get_dcost(vector<vector<int>>& land, long long P, long long Q, int height)
{
    long long cost = 0;
    for(const auto& lan : land)
        for(const int l : lan)
        {
            if(l >= height)
                cost -= Q;
            else
                cost += P;
        }
    return cost;
}

long long solution(vector<vector<int>> land, int P, int Q) {
    int left = 0, right = 1e9;
    long long min_cost = LLONG_MAX;
    while(left <= right)
    {
        const int mid = (left+right)/2;
        const long long cost = get_cost(land,P,Q,mid), dcost = get_dcost(land,P,Q,mid);
        min_cost = min(min_cost,cost);
        if(dcost >= 0)
            right = mid-1;
        else
            left = mid+1;
    }
    return min_cost;
}