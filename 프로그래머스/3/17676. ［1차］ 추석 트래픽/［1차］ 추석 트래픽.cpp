#include <string>
#include <vector>

using namespace std;

int get_time(const string& line)
{
    int time = stoi(line.substr(11,2))*3600000;
    time += stoi(line.substr(14,2))*60000;
    time += stoi(line.substr(17,2))*1000;
    time += stoi(line.substr(20,3));
    return time;
}
int get_sec(const string& line)
{
    int sec = stoi(line.substr(24,1))*1000;
    if(line[25] == '.')
        sec += stoi(line.substr(26,(int)(line.size())-2));
    return sec;  
}

int solution(vector<string> lines) {
    vector<vector<int>> timelines;
    for(const string& line : lines)
    {   
        const int time = get_time(line), sec = get_sec(line);
        timelines.push_back({time-sec+1,time});
    }
    int answer = 0;
    for(const auto& mainline : timelines)
    {
        const int begin = mainline[1], end = begin+999;
        int overlap = 0;
        for(const auto& subline : timelines)
            if(subline[1] >= begin && end >= subline[0])
                ++overlap;
        answer = max(answer,overlap);
    }
    return answer;
}