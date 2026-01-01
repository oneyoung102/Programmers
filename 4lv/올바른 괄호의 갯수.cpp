//2025-11-06 16:41:46
//https://school.programmers.co.kr/learn/courses/30/lessons/12929

#include <vector>

using namespace std;

int solution(int n) {
    vector<int> dp1(n+1,0); //n쌍을 사용했을 때 쪼갤 수 없는 괄호쌍들의 개수
    vector<int> dp2(n+1,0); //총개수
    dp1[0] = 1;
    dp2[0] = 1;
    for(int i = 1 ; i <= n ; ++i)
    {
        dp1[i] = dp2[i-1];
        for(int j = 1 ; j <= i ; ++j)
            dp2[i] += dp1[j]*dp2[i-j];
    }
    return dp2[n];
}
