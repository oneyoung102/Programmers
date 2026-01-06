#include <string>
#include <vector>

using namespace std;
inline int oclock(int n){return 60*(n/100)+n%100;}
int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();
    const int saturday = (14-startday-1)%7, sunday = 7-startday;
    for(int i = 0 ; i < timelogs.size() ; ++i)
        for(int j = 0 ; j < timelogs[0].size() ; ++j)
            if(j != saturday && j != sunday)
                if(oclock(timelogs[i][j]) > oclock(schedules[i])+10)
                {
                    --answer;
                    break;
                }
    return answer;
}