#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<long long> a) {
    int plus = (a.size()-1)/2;
    sort(a.begin(),a.end(),greater<long long>());
    long long answer = a.front();
    for(int i = 1 ; i < a.size() ; ++i)
    {
        if(plus > 0)
        {
            answer += a[i];
            --plus;
        }
        else
            answer -= a[i];
    }
    return answer;
}

int main()
{
    printf("%lld",solution({1,-1,0}));
    //{4,-2,3}
    //{5,7,0,-1}
    return 0;
}