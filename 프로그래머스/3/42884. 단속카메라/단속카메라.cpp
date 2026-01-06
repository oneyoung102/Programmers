#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    for(auto& r : routes)
        sort(r.begin(),r.end());
    sort(routes.begin(),routes.end(),[](vector<int>& a,vector<int>& b){
        if(a[0] < b[0]) return true;
        if(a[0] == b[0]) return a[1] > b[1];
        return false;
    });
    int answer = 1;
    int left = -30000, right = 30000;
    for(const auto& r : routes)
    {
        left = max(left,r[0]);
        right = min(right,r[1]);
        if(left > right)
        {
            ++answer;
            left = r[0];
            right = r[1];
        }
    }
    return answer;
}