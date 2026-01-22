#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long q1_sum = accumulate(queue1.begin(),queue1.end(),0ll);
    long long q2_sum = accumulate(queue2.begin(),queue2.end(),0ll);
    const long long total_sum = q1_sum+q2_sum;
    
    if(total_sum%2 == 1)
        return -1;
    
    int answer = 0;
    const long long total_sum_half = total_sum/2;
    queue<int> q1;
    for_each(queue1.begin(),queue1.end(),[&q1](int x){
        q1.push(x);
    });
    queue<int> q2;
    for_each(queue2.begin(),queue2.end(),[&q2](int x){
        q2.push(x);
    });
    while(true)
    {
        if(q1_sum > total_sum_half)
        {
            q2.push(q1.front());
            q1_sum -= q1.front();
            q1.pop();
        }
        else if(q1_sum < total_sum_half)
        {
            q1.push(q2.front());
            q1_sum += q2.front();
            q2.pop();
        }
        else
            break;
        if(q1.empty() || q2.empty() || answer == INT_MAX)
            return -1;
        ++answer;
    }
    return answer;
}