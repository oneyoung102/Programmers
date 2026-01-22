#include <string>
#include <vector>
#include <numeric>

using namespace std;
vector<int> answer;
void calc_position(vector<int>& numbers, long long k, long long factorial, int n)
{
    if(n == 0)
        return;
    const int pos = (k-1)/factorial;
    answer.push_back(numbers[pos]);
    numbers.erase(numbers.begin()+pos);
    calc_position(numbers,k-pos*factorial,factorial/((n == 1) ? 1 : n-1),n-1);
}


vector<int> solution(int n, long long k) {
    vector<int> numbers(n);
    iota(numbers.begin(),numbers.end(),1);
    long long factorial = 1;
    for(int i = 2 ; i <= n-1 ; ++i)
        factorial *= i;
    calc_position(numbers,k,factorial,n);
    return answer;
}