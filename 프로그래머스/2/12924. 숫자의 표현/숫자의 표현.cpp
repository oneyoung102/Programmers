#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    if(n == 1)
        return 1;
    int answer = 1; // n자체일 때
    int i = 0, j = 1, sum = 1;
    while(i != (n+1)/2)
    {
        if(sum < n)
            sum += ++j;
        else if(sum > n)
            sum -= ++i;
        else
        {
            ++answer;
            sum -= ++i;
        }
    }
    return answer;
}