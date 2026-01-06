#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 1;
    if(n > 2)
    {
        for(int i = 3 ; i <= n ; i+=2)
        {
            int j = 2;
            int range = int(sqrt(i));
            while(j <= range)
            {
                if(i%j == 0)
                    break;
                ++j;
            }
            if(j == range+1)
                ++answer;
        }
    }
    return answer;
}