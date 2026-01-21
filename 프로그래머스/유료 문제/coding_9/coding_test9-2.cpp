#include <string>
#include <vector>
#include <set>

using namespace std;

long long solution(int n) {
    set<long long> numbers;
    for(long long i = 1 ; i <= n ; ++i)
        numbers.insert(i*(i+1));
    
    const long long biggest = *(--numbers.end());

    for(int i = 3 ;; ++i)
    {
        long long num = 1;
        int j = 0, k = 1;
        while(num < biggest)
        {
            num *= k+j;
            if(j++ == i-1)
            {
                numbers.insert(num);
                num = 1;
                ++k;
                j = 0;
            }
        }
        if(k == 1)
            break;
    }
    int count = 1;
    for(auto it = numbers.begin() ; it != numbers.end() ; ++it, ++count)
        if(count == n)
            return *it;
    return -1;
}

int main()
{
    printf("%lld",solution(1000000));
    return 0;
}