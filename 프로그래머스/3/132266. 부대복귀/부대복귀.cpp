#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> solution(int N, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> min_dist(N+1,INT_MAX);
    min_dist[destination] = 0;
    vector<vector<int>> link(N+1,vector<int>());
    for(const auto& r : roads)
    {
        link[r[0]].push_back(r[1]);
        link[r[1]].push_back(r[0]);
    }
    queue<int> node;
    node.push(destination);
    while(!node.empty())
    {
        const int n = node.front();
        node.pop();
        for(const int child : link[n])
            if(min_dist[child] > min_dist[n]+1)
            {
                min_dist[child] = min_dist[n]+1;
                node.push(child);
            }
    }
    vector<int> answer;
    for(const int s : sources)
    {
        if(min_dist[s] == INT_MAX)
            answer.push_back(-1);
        else
            answer.push_back(min_dist[s]);
    }
    return answer;
}