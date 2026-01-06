#include <vector>
#include <queue>
#include <climits>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    vector<vector<pair<int,int>>> graph(n);
    for (auto& e : costs) {
        graph[e[0]].push_back({e[1], e[2]});
        graph[e[1]].push_back({e[0], e[2]});
    }

    vector<bool> visited(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0, 0}); // (비용, 시작섬)
    int total_cost = 0;

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        if (visited[node]) continue;
        visited[node] = true;
        total_cost += cost;

        for (auto [next, w] : graph[node]) {
            if (!visited[next]) {
                pq.push({w, next});
            }
        }
    }

    return total_cost;
}