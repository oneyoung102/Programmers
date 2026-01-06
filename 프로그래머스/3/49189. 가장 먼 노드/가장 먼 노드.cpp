#include <vector>
#include <queue>
#include <utility>

using namespace std;
using T = pair<int,int>;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> link;
    for(const auto& e : edge)
    {
        const int m = max(e[0],e[1]);
        while(link.size() < m)
            link.push_back(vector<int>());
        link[e[0]-1].push_back(e[1]-1);
        link[e[1]-1].push_back(e[0]-1);
    }

    vector<int> dist(link.size(),20000);
    vector<bool> visited(link.size(),false);
    dist[0] = 0;
    int answer = 0, length = 0;
    priority_queue<T,vector<T>,greater<T>> pq;
    pq.push(make_pair(0,0)); // dist, node;
    while(!pq.empty())
    {
        const int d = pq.top().first, node = pq.top().second;
        pq.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        if(length < d)
        {
            answer = 0;
            length = d;
        }
        if(length == d) ++answer;
        for(const int p : link[node])
            if(dist[p] > d+1)
            {
                dist[p] = d+1;
                pq.push(make_pair(dist[p],p));
            }
    }
    return answer;
}