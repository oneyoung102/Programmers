#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    const vector<int> days = {31,29,31,30,31,30,31,31,30,31,30,31};
    const vector<string> week = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int total_day = 4+b;
    for(int i = 0 ; i < a-1 ; ++i)
        total_day += days[i];
    return week[total_day%week.size()];
}