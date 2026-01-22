#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(const long long n : numbers)
    {
        if(n == 0 || n == 1)
        {
            answer.push_back(n+1);
            continue;
        }
        long long new_n = n, bit = 1ll;
        while(true)
        {
            if((bit&n) == 0)
            {
                new_n |= bit;  
                if(((bit>>1)&n) != 0)
                    new_n -= (bit>>1);
                break;
            }
            bit <<= 1;
        }
        answer.push_back(new_n);       
    }
    return answer;
}