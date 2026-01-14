#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end());
    for(int i = citations.back() ; i >= 0 ; --i)
    {
        const auto it = lower_bound(citations.begin(),citations.end(),i);
        if(distance(it,citations.end()) >= i)
            return i;
    }
    return 0;
}