#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;

inline int time_to_int(string& s)
{
    const int hour = stoi(s.substr(0,2));
    const int minute = stoi(s.substr(3,2));
    return hour*60+minute;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    const int day_end = 1440-1;
    map<string,int> car_time;
    for(const string& s : records)
    {
        stringstream ss(s);
        string time = "", number = "", act = "";
        ss >> time >> number >> act;
        if(act == "IN")
            car_time[number] += day_end-time_to_int(time);
        else
            car_time[number] -= day_end-time_to_int(time);
    }
    
    vector<int> answer;
    for(const auto& ct : car_time)
    {
        const int time = ct.second;
        const int unit_time = ceil(max(time-fees[0],0)/(fees[2]+0.0));
        answer.push_back(fees[1] + unit_time*fees[3]);
    }
    return answer;
}