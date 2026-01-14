#include <queue>
#include <deque>
#include <vector>
#include <utility>

using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<int,vector<int>,less<int>> pq(priorities.begin(),priorities.end());
    deque<pair<int,int>> dq;
    for(int i = 0 ; i < priorities.size() ; ++i)
        dq.push_back(make_pair(i,priorities[i]));
    int answer = 0;
    while(!pq.empty())
    {
        ++answer;
        const int maxi = pq.top();
        pq.pop();
        while(maxi != dq.front().second)
        {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        if(dq.front().first == location)
            return answer;
        dq.pop_front();
    }
    return answer;
}