#include <vector>
#include <utility>

using namespace std;

int get_gcd(int a, int b)
{
    if(a > b) std::swap(a,b);
    while(a != 0)
    {
        const int temp = a;
        a = b%a;
        b = temp;
    }
    return b;
}

int solution(vector<int> arr) {
    int answer = 1;
    for(const int n : arr)
        answer = answer*n/get_gcd(answer,n);
    return answer;
}