#include <set>
#include <vector>

using namespace std;

int solution(vector<int> elements) {
    const int es = elements.size();
    set<int> series_sum;
    for(int i = 0 ; i < es ; ++i)
    {
        int sum = 0;
        for(int j = 0 ; j < es; ++j)
        {
            sum += elements[(i+j)%es];
            series_sum.insert(sum);
        }
    }
    return series_sum.size();
}