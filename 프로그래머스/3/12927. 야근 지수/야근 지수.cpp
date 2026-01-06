#include <vector>
#include <algorithm>
#include <set>

using namespace std;

long long solution(int N, vector<int> works) {
    works.push_back(0);
    sort(works.begin(),works.end());

    set<int,greater<int>> numbers;
    for_each(works.begin(),works.end(),[&numbers](int x){
        numbers.insert(x);
    });
    numbers.erase(numbers.begin());

    for(const int n : numbers)
    {
        const int init = distance(works.begin(),upper_bound(works.begin(),works.end(),n));
        size_t i = init;
        while(N > 0 && works.back() != n)
        {
            --works[i];
            --N;
            ++i;
            if(i == works.size())
                i = init;
        }
        if(N <= 0)
            break;
    }
    
    long long answer = 0ll;
    for_each(works.begin(),works.end(),[&answer](long long x){
        answer += x*x;
    });
    return answer;
}