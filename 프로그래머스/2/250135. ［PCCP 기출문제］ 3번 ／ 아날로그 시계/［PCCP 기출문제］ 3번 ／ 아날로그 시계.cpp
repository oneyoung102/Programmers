#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    struct arrow{
        double h, m, s;
        arrow(double a, double b, double c) : h(a), m(b), s(c) {}; 
    };
    int answer = 0;
    bool before_noon = false;
    const int fromtime = s1+m1*60+h1*3600, totime = s2+m2*60+h2*3600;
    arrow Arrow(fmod((double)(fromtime)/3600,12)*5,(double)(fromtime%3600)/60,s1);
    if(s1 == 0 && m1 == 0)
    {
        ++answer;
        before_noon = true;
    }
    for(int i = fromtime+1 ; i <= totime ; ++i)
    {
        if(!before_noon)
        {
            Arrow.h = fmod((double)(i)/3600,12)*5;
            Arrow.m = (double)(i%3600)/60;
            Arrow.s = (i%60);
            if(Arrow.m != 0 || Arrow.s != 0)
            {
                int second = (Arrow.s==0) ? 60 : Arrow.s;
                if(second - Arrow.m < 1 && second - Arrow.m > 0)
                    ++answer;
                if(second - Arrow.h < 1 && second - Arrow.h > 0)
                    ++answer;
            }
            else
            {
                before_noon = true;
                ++answer;
            }
        }
        else
            before_noon = false;
    }
    return answer;
}