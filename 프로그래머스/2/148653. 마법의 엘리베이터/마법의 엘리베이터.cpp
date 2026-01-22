#include <string>
#include <vector>


using namespace std;

int teen(int sub, int mode)
{
    int answer = 0;
    for(int i = 10 ; sub !=0 ; i*=10)
    {
        if(sub%i + mode > 0.5*i)
        {
            answer += 10-(sub%i)/(i/10);
            sub += i-sub%i;
        }
        else
        {
            answer += (sub%i)/(i/10);
            sub -= sub%i;
        }
    }
    return answer;
}

int solution(int storey) {
    return min(teen(storey,1),teen(storey,0));
}