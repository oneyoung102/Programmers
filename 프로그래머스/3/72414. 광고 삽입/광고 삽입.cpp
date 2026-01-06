#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int timeToInt(string& t, int init)
{
    return stoi(t.substr(init,2))*3600+stoi(t.substr(init+3,2))*60+stoi(t.substr(init+6,2));
}
string intToTime(int n)
{
    const string t = to_string(n);
    if(t.size() == 1)
        return '0'+t;
    return t;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    const int RIGHT = 0, LEFT = 1;
    const int pt = timeToInt(play_time,0), at = timeToInt(adv_time,0);
    vector<vector<int>> timePoint;
    for(string& log : logs)
    {
        timePoint.push_back({timeToInt(log,0),LEFT});
        timePoint.push_back({timeToInt(log,9),RIGHT});
    }
    sort(timePoint.begin(),timePoint.end());

    vector<int> viewTime(pt,0);
    int level = 0, maxLevel = 0;
    vector<int> left = timePoint[0];
    for(int i = 1 ; i < timePoint.size() ; ++i)
    {
        const vector<int>& right = timePoint[i];
        if(left[1] == LEFT)
            ++level;
        else if(left[1] == RIGHT) 
            --level;
        if(level != 0)
            for(int j = left[0] ; j < right[0] ; ++j)
                viewTime[j] = level;
        left = std::move(right);   
    }
    int insertTime = 0;
    long long maxAccumulateTime = 0;
    for(int i = 0 ; i < at ; ++i)
        maxAccumulateTime += viewTime[i];
    long long accumulateTime = maxAccumulateTime;
    for(int from = 1 ; from <= pt-at ; ++from)
    {
        accumulateTime += -viewTime[from-1]+viewTime[from+at-1];
        if(accumulateTime > maxAccumulateTime)
        {
            insertTime = from;
            maxAccumulateTime = accumulateTime;
        }
    }
    const string answer = intToTime(insertTime/3600)+':'+intToTime((insertTime%3600)/60)+':'+intToTime(insertTime%60);
    return answer;
}