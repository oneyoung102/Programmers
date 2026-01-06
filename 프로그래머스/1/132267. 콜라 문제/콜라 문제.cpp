#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n >= a)
    {
        const int add = (n/a)*b;
        answer += add;
        n = add+n%a;
    }
    return answer;
}