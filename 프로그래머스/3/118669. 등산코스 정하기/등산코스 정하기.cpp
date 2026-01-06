#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
using T = pair<int,int>;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    const int MAX_TIME = 1e7+1;
    vector<vector<T>> links(n,vector<T>());
    for(const auto& path : paths)
    {
        const int node1 = path[0]-1, node2 = path[1]-1, time = path[2];
        links[node1].push_back(make_pair(node2,time));
        links[node2].push_back(make_pair(node1,time));
    }

    vector<bool> is_summit(n,false), is_gate(n,false);
    for(const int summit : summits)
        is_summit[summit-1] = true;
    for(const int gate : gates)
        is_gate[gate-1] = true;

    int optimal_summit = -1, optimal_intensity = MAX_TIME;
    vector<bool> visited(n,false);
    priority_queue<T,vector<T>,greater<T>> pq;
    for(const int gate : gates)
        pq.push(make_pair(0,gate-1));    
    while(!pq.empty())
    {
        const auto [intensity,node] = pq.top();
        pq.pop();
        if(intensity > optimal_intensity)
            continue;
        if(is_summit[node])
        {
            if(optimal_intensity > intensity)
            {
                optimal_intensity = intensity;
                optimal_summit = node; 
            }
            else if(optimal_intensity == intensity && optimal_summit > node)
                optimal_summit = node;
            continue;
        }
        visited[node] = true;
        for(const auto [link,inte] : links[node])
        {
            if(visited[link] || is_gate[link])
                continue;
            const int time = max(inte,intensity);
            if(time <= optimal_intensity)
                pq.push(make_pair(time,link));
        }
    }
    return {optimal_summit+1,optimal_intensity};
}