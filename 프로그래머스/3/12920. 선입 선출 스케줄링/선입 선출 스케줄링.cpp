#include <vector>

using namespace std;

int solution(int n, vector<int> cores) {
    int left = 0, right = 1e9, time = -1;
    while(left <= right)
    {
        const int mid = (left+right)/2;
        long long sum = 0;
        for(const int c : cores)
            sum += mid/c+1;
        if(sum >= n)
        {
            time = mid;
            right = mid-1;
        }
        else
            left = mid+1;
    }
    int before_sum = 0;
    if(time != 0)
        for(const int c : cores)
            before_sum += (time-1)/c+1;
    int idx = n-before_sum;
    for(int i = 0 ; i < cores.size() ; ++i)
        if(time%cores[i] == 0 && --idx == 0)
            return i+1;
    return -1;
}