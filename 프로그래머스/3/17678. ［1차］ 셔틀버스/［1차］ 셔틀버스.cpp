#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> broadTime;
    for(const auto& tt : timetable)
    {
        const int time = stoi(tt.substr(0,2))*60+stoi(tt.substr(3,2));
        broadTime.push_back(time);
    }
    sort(broadTime.begin(),broadTime.end());
    int ans = 0, startTime = 540, person = 0, i = 0;
    while(i < broadTime.size() && n > 0)
    {
        const bool broadPossible = startTime >= broadTime[i];
        if(broadPossible)
            ++person;
        if(person == m || !broadPossible || i == broadTime.size()-1)
        {
            ans = max(ans,(person == m) ? broadTime[i]-1 : startTime);
            startTime += t;
            person = 0;
            --n;
        }
        if(broadPossible)
            ++i;
    }
    string answer = "";
    const int hour = ans/60, minute = ans%60;
    if(hour < 10) answer += '0';
    answer += to_string(hour);
    answer += ':';
    if(minute < 10) answer += '0';
    answer += to_string(minute);
    return answer;
}