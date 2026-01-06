#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1 ; i <= number ; ++i)
    {
        int count;
        const double mid = sqrt(i);
        if(i == 1)
            count = 1;
        else
        {
            count = 2;
            if((int)mid == mid)
                ++count;
        }
        for(int j = 2 ; j < mid ; ++j)
            if(i%j == 0)
                count+=2;
        if(count > limit)
            answer += power;
        else
            answer += count;
        
    }
    return answer;
}