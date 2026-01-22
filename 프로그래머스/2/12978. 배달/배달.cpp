#include <vector>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    vector<int> dist(N,INT_MAX);
    dist[0] = 0;
    vector<vector<pair<int,int>>> child(N);
    for(const vector<int>& r : road)
    {
        child[r[0]-1].push_back(make_pair(r[1]-1,r[2]));
        child[r[1]-1].push_back(make_pair(r[0]-1,r[2]));
    }
    queue<int> node;
    node.push(0);
    while(!node.empty())
    {
        const int start = node.front();
        node.pop();
        for(const auto& c : child[start])
            if(dist[c.first] > dist[start]+c.second)
            {
                dist[c.first] = dist[start]+c.second;
                node.push(c.first);
            }
    }
    int answer = 0;
    for(const int d : dist)
        if(d <= K)
            ++answer;
    return answer;
}