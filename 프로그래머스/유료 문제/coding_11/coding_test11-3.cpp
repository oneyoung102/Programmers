#include <vector>
#include <climits>

using namespace std;

int solution(int n, int k)
{
    if(n%2 == 1 && k%2 == 0)
        return -1;
    int answer = 1;
    int remainder = n%k;
    long long ntoten = 10;
    while(ntoten < n)
        ntoten *= 10;
    while(remainder != 0)
    {
        if(answer++ > k)
            return -1;
        remainder = (remainder*ntoten + n)%k;
    }
    return answer;
}

int main()
{
    printf("%d",solution(0.974e9,11));
    return 0;
}