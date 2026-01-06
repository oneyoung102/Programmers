#include <string>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int beforescore = 0;
    int presentscore = 0;
    const char* dartresult = dartResult.c_str();
    for(int i = 0 ; i < dartResult.length() ; i+=2)
    {
        presentscore = (dartresult[i+1]=='0') ? 10 : dartresult[i] - '0';
        if(dartresult[i+1]=='0')
            i+=1;
        presentscore = pow(presentscore,(dartresult[i+1]=='S') ? 1 : (dartresult[i+1]=='D') ? 2 : 3);
        if((dartresult[i+2] == '*'||dartresult[i+2] == '#')&&i+2<dartResult.length())
        {
            if(dartresult[i+2] == '*')
            {
                answer-=beforescore;
                presentscore*=2;
                beforescore*=2;
            }
            else
            {
                beforescore=0;
                presentscore*=-1; 
            }                  
            i+=1;
        }
        else
            beforescore=0;
        answer+=presentscore+beforescore;
        beforescore = presentscore;
    }
    return answer;
}