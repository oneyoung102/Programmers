#include <vector>
#include <set>

using namespace std;

int solution(vector<int> a) {
    if(a.size() == 1) return 1;
    int answer = 2;
    set<int> suba(a.begin()+2,a.end());
    int left_min = a[0], right_min = *(suba.begin());
    for(int i = 1 ; i < a.size()-1 ; ++i)
    {
        const int mid = a[i];
        if(left_min > mid || right_min > mid)
            ++answer;
        left_min = min(mid,left_min);
        suba.erase(a[i+1]);
        right_min = *(suba.begin());
    }
    return answer;
}