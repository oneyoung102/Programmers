#include <string>
#include <math.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long R1 = r1;
    long long R2 = r2;
    for(long long i = 1 ; i <= R2 ; i++)  //-> x
    {
        long long maxy = static_cast<long long>(pow(R2*R2-i*i,0.5));
        long long miny = (R1<i) ? 0 : static_cast<long long>(pow(R1*R1-i*i,0.5));
        answer += maxy-miny+1;
        if(miny*miny<R1*R1-i*i)
            answer--;
    }
    return answer*4;
}