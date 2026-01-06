#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int a = 0;
    for(int b = 0 ; b < B.size() ; ++b)
    {   
        if(A[a] < B[b])
        {
            ++a;
            ++answer;
        }
    }
    return answer;
}