#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    string num = "";
    while(n != 0)
    {
        num += n%k +'0';
        n /= k;
    }
    reverse(num.begin(),num.end());
    num += '0';

    int answer = 0;
    string s = "";
    for(const char c : num)
        if(c == '0')
        {
            if(s != "")
            {
                const long long number = stoll(s);
                s = "";
                if(number == 1)
                    continue;
                if(number == 2)
                {
                    ++answer;
                    continue;
                }
                bool isPrime = true;
                const int root = sqrt(number);
                for(int i = 3 ; i <= root ; i += 2)
                    if(number%i == 0)
                    {
                        isPrime = false;
                        break;
                    }
                if(isPrime)
                    ++answer;
            }
        }
        else
            s += c;
    return answer;
}