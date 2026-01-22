#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    const int length = prices.size();
    vector<int> indexes(10001,length);
    for(int i = length-1 ; i >= 0 ; --i)
    {
        int idx = length-1;
        for(int j = prices[i]-2 ; j >= 0 ; --j)
            idx = min(idx,indexes[j]);
        indexes[prices[i]-1] = i;
        answer.push_back(idx-i);
    }
    reverse(answer.begin(),answer.end());
    return answer;
}