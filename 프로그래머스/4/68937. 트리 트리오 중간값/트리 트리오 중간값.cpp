#include <vector>
#include <queue>
#include <utility>

using namespace std;
using T = pair<int,int>;

int solution(int n, vector<vector<int>> edges) {
    vector<vector<int>> links(n);
    for(const auto& edge : edges)
    {
        links[edge[0]-1].push_back(edge[1]-1);
        links[edge[1]-1].push_back(edge[0]-1);
    }

    vector<int> starts;
    int far_node = 0;
    for(int i = 0 ; i < 2 ; ++i)
    {
        int far_dist = 0;
        queue<T> nodes;
        vector<bool> visited(n,false);
        nodes.push(make_pair(0,far_node));
        while(!nodes.empty())
        {
            const auto [dist,node] = nodes.front();
            nodes.pop();
            visited[node] = true;
            if(dist > far_dist)
            {
                far_node = node;
                far_dist = dist;
            }
            for(const int link : links[node])
                if(!visited[link])
                    nodes.push(make_pair(dist+1,link));
        }
        starts.push_back(far_node);
    }

    int answer = 0;
    for(const int start : starts)
    {
        queue<T> nodes;
        vector<bool> visited(n,false);
        nodes.push(make_pair(0,start));
        while(!nodes.empty())
        {
            const auto [dist,node] = nodes.front();
            nodes.pop();
            visited[node] = true;
            if(node != starts[0] && node != starts[1])
                answer = max(answer,dist);
            for(const int link : links[node])
                if(!visited[link])
                    nodes.push(make_pair(dist+1,link));
        }
    }
    return answer;
}