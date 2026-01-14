#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    sort(tangerine.begin(),tangerine.end());
    vector<int> count(tangerine.back(),0);
    for(const int t : tangerine)
        ++count[t-1];
    tangerine.erase(unique(tangerine.begin(),tangerine.end()),tangerine.end());
    for(size_t i = 0 ; i < tangerine.size() ; ++i)
        tangerine[i] = count[tangerine[i]-1];
    sort(tangerine.begin(),tangerine.end());
    int sum = 0;
    for(size_t i = tangerine.size()-1 ; i >= 0 ; --i)
    {
        ++answer;
        sum += tangerine[i];
        if(sum >= k) break;
    }
    return answer;
}