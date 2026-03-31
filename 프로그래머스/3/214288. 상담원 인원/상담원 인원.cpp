#include <functional>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

void allot(vector<vector<int>>& consultants, vector<int>& base, int idx, int count)
{
    if(idx == base.size())
    {
        if(count == 0)
            consultants.push_back(base);
        return;
    }
    for(int c = 0 ; c <= count ; ++c)
    {
        base[idx] += c;
        allot(consultants,base,idx+1,count-c);
        base[idx] -= c;
    }
}

int solution(int k, int n, vector<vector<int>> reqs) {
    stable_sort(reqs.begin(),reqs.end(),[](const vector<int>& x, const vector<int>& y){
        return x[0] < y[0];
    });
    vector<vector<int>> consultants; 
    vector<int> base(k,1);
    allot(consultants,base,0,n-k);

    int min_wait_time_sum = INT_MAX;
    for(const auto& consultant : consultants)
    {
        int wait_time_sum = 0;
        vector<priority_queue<int,vector<int>,greater<int>>> consult_ends(k);
        for(int i = 0 ; i < k ; ++i)
            for(int j = 0 ; j < consultant[i] ; ++j)
                consult_ends[i].push(0);
        for(const auto& req : reqs)
        {
            const int ask = req[0], time = req[1], allot = req[2]-1;
            const int end = consult_ends[allot].top(); consult_ends[allot].pop();
            const int start = max(ask,end);
            wait_time_sum += start-ask;
            consult_ends[allot].push(start+time);
        }
        min_wait_time_sum = min(min_wait_time_sum,wait_time_sum);
    }
    return min_wait_time_sum;
}