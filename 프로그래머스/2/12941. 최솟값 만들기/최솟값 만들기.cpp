#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(),A.end(),less<int>());
    sort(B.begin(),B.end(),greater<int>());
    for(size_t i = 0 ; i < A.size() ; ++i)
        answer += A[i]*B[i];
    return answer;
}