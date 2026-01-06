#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

using T = pair<int,int>;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> costs(n,vector<int>(n,2e7));
    for(int i = 0 ; i < n ; ++i)
        costs[i][i] = 0;
    vector<vector<int>> links(n,vector<int>());
    for(const auto& f : fares)
    {
        costs[f[0]-1][f[1]-1] = f[2];
        costs[f[1]-1][f[0]-1] = f[2];
        links[f[0]-1].push_back(f[1]-1);
        links[f[1]-1].push_back(f[0]-1);
    }
    for(const int main_node : {s-1,a-1,b-1})
    {
        priority_queue<T,vector<T>,greater<T>> pq;
        for(const int child_node : links[main_node])
            pq.push(make_pair(costs[main_node][child_node],child_node)); // 비용, 노드 번호
        while(!pq.empty())
        {
            const auto [cost,node] = pq.top();
            pq.pop();
            for(const int linked_node : links[node])
            {
                const int new_cost = cost+costs[node][linked_node];
                if(new_cost < costs[main_node][linked_node])
                {
                    costs[main_node][linked_node] = new_cost;
                    costs[linked_node][main_node] = new_cost;
                    pq.push(make_pair(new_cost,linked_node));
                }
            }
        }
    }
    int answer = 6e7;
    for(int i = 0 ; i < n ; ++i)
        answer = min(answer,costs[s-1][i]+costs[i][a-1]+costs[i][b-1]);
    return answer;
}