#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0, end = 0, sum = 0, min = sequence.size(), pos = 0;
    while(end < sequence.size())
    {
        sum+=sequence[end];
        while(start<=end&& k < sum)
        {
            sum-=sequence[start];
            start++;
        }
        if(sum == k && end-start < min)
        {
            min = end-start;
            pos = start;
            if(min==0)
                break;
        }
        end++;
    }
    answer.push_back(pos);
    answer.push_back(pos+min);
    return answer;
}