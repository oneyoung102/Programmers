#include <vector>
#include <queue>

using namespace std;

void calculate_route(vector<vector<int>>& routes, vector<int>& route, int count)
{
    if(count == 0)
    {
        routes.push_back(route);
        return;
    }
    for(int p = 1 ; p <= 3 ; ++p)
    {
        if(!route.empty() && route.back() == p)
            continue;
        route.push_back(p);
        calculate_route(routes,route,count-1);
        route.pop_back();
    }
}

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    vector<vector<int>> linked(n);
    vector<vector<int>> pipe(n,vector<int>(n,0));
    for(const auto& edge : edges)
    {
        const int n1 = edge[0]-1, n2 = edge[1]-1, p = edge[2];
        pipe[n1][n2] = p;
        pipe[n2][n1] = p;
        linked[n1].push_back(n2);
        linked[n2].push_back(n1);   
    }
    vector<vector<int>> routes;
    vector<int> route;
    calculate_route(routes,route,k);

    int max_infections = 0;
    for(const auto& route : routes)
    {
        int infections = 0;
        queue<pair<int,int>> infects; //{node,pipe_idx}
        vector<bool> infected(n,false);
        infects.push(make_pair(infection-1,0));
        while(!infects.empty())
        {
            const auto[node,pipe_idx] = infects.front();
            infects.pop();
            if(infected[node])
                continue;
            infected[node] = true;
            ++infections;
            for(const int link : linked[node])
                if(!infected[link])
                {
                    int next_pipe = pipe_idx;
                    while(next_pipe < k && route[next_pipe] != pipe[node][link])
                        ++next_pipe;
                    if(next_pipe < k)
                        infects.push(make_pair(link,next_pipe));
                }
        }
        max_infections = max(max_infections,infections);
    }
    return max_infections;
}