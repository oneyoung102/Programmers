#include <vector>
#include <queue>

using namespace std;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    vector<bool> visitable(n,true), visited(n,false);
    vector<int> openable(n,-1);
    for(const auto& od : order)
    {
        visitable[od[1]] = false;
        openable[od[0]] = od[1];
    }
    vector<vector<int>> linked(n);
    for(const auto& p : path)
    {
        linked[p[0]].push_back(p[1]);
        linked[p[1]].push_back(p[0]);
    }
    
    int visit_count = 0;
    queue<int> nodes;
    nodes.push(0);
    while(!nodes.empty())
    {
        const int node = nodes.front();
        nodes.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        ++visit_count;
        if(!visitable[node])
            continue;
        const int open_node = openable[node];
        if(open_node != -1)
        {
            visitable[open_node] = true;
            if(visited[open_node])
            {
                nodes.push(open_node);
                visited[open_node] = false;
                --visit_count;
            }
        }
        for(const int link : linked[node])
            if(!visited[link])
                nodes.push(link);
    }
    return visit_count == n;
}