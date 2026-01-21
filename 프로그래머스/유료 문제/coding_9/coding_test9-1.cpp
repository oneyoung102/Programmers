#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int c, int d, string e) {
    int answer = 0;
    int day = -1;
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    const int wlength = week.size();
    for(int i = 0 ; i < wlength ; ++i)
        if(week[i] == e)
        {
            day = i;
            break;
        }
    const int arrive = c*60+d;
    int minute = 0, date = 0;
    bool wait = false;
    while(date < 30)
    {
        if(!wait && minute >= arrive)
        {
            if(day != 0 && day != wlength-1)
                answer += minute - arrive;
            wait = true;
        }
        else if(wait && minute > 1440)
        {
            minute -= 1440;
            wait = false;
            ++day;
            day %= wlength;
            ++date;
            continue;
        }
        minute += a*60+b;
    }
    return answer;
}

int main()
{
    printf("%d",solution(0,1,8,50,"SAT"));
    //1,0,11,0,"SUN"
    //0,20,7,15,"MON"
    //
    //7,0,6,40,"FRI"
    return 0;
}