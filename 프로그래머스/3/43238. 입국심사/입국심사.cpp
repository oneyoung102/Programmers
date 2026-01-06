#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    const long long N = n;
    sort(times.begin(),times.end());
    long long left = 1ll, right = times.back()*N, answer = right;
    while(left <= right)
    {
        long long mid = (right+left)/2ll;
        long long sum = 0ll;
        for(const int t : times)
            sum += mid/t;
        if(sum >= N)
        {
            answer = min(answer,mid);
            right = mid-1;
        }
        else
            left = mid+1;        
    }
    return answer;
}