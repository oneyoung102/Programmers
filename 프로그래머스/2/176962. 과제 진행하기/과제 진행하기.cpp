#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<int> homework;
    vector<int> whole_time;
    
    auto ttoi = [](string a) {return stoi(a.substr(0,2))*60+stoi(a.substr(3,2));};
    
    sort(plans.begin(),plans.end(),[ttoi](vector<string> a, vector<string> b)
    {
        return ttoi(a[1]) < ttoi(b[1]);
    });
    
    for(vector<string> it : plans)
        whole_time.push_back(stoi(it[2]));
    
    int pw = 0;
    while(!homework.empty() || pw != plans.size())
    {
        if(pw < plans.size()-1)
        {
            int rest = ttoi(plans[pw+1][1]) - ttoi(plans[pw][1]) - whole_time[pw];
            if(rest >= 0)
            {
                answer.push_back(plans[pw][0]);
                if(!homework.empty())
                {
                    int h = homework.top();
                    while(rest > 0)
                    {
                        --whole_time[h];
                        --rest;
                        if(whole_time[h] == 0)
                        {
                            answer.push_back(plans[h][0]);
                            homework.pop();
                            if(!homework.empty())
                                h = homework.top();
                            else
                                break;
                        }
                    }
                }
            }
            else
            {
                homework.push(pw);
                whole_time[pw] = -rest;
            }
        }
        else
        {
            answer.push_back(plans[pw][0]);
            if(!homework.empty())
            {
                while(!homework.empty())
                {
                    answer.push_back(plans[homework.top()][0]);
                    homework.pop();
                } 
            }
        }
        ++pw;
    }
    return answer;
}