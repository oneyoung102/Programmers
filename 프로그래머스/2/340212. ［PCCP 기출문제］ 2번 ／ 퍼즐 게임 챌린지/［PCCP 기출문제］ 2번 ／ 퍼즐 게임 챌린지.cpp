#include <string>
#include <vector>
#include <algorithm>

using namespace std;
long long calculate_time(int level, vector<int> diffs, vector<int> times, long long limit)
{
    long long totaltime = 0;
    for(int i = 0; i < diffs.size(); i++)
    { 
        if(diffs[i] > level)
            totaltime += (diffs[i] - level) * (times[i] + times[i-1]);
        totaltime += times[i];
        if(totaltime  > limit)
            break;
    }
    return totaltime;
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int low = 1, high = *max_element(diffs.begin(), diffs.end());
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (calculate_time(mid, diffs, times, limit) <= limit)
            high = mid;
        else low = mid + 1;
    }
    return low;
}