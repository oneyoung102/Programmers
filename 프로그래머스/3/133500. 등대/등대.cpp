#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> lighthouse) {
    vector<vector<int>> links(n);
    vector<int> link_count(n,0);
    for(const auto& lh : lighthouse)
    {
        links[lh[0]-1].push_back(lh[1]-1);
        links[lh[1]-1].push_back(lh[0]-1);
        ++link_count[lh[0]-1];
        ++link_count[lh[1]-1];
    }

    const auto compare = [&link_count](int x, int y){
        return link_count[x] >= link_count[y];
    };
    priority_queue<int,vector<int>,decltype(compare)> pq(compare);
    for(int i = 0 ; i < n ; ++i)
        pq.push(i);
    int answer = 0;
    while(!pq.empty())
    {
        const int node = pq.top();
        if(link_count[node] >= 1)
        {
            const int linked = *find_if(links[node].begin(),links[node].end(),[&link_count](int x){
                return link_count[x] >= 1;
            });
            ++answer;
            for(const int link : links[linked])
                --link_count[link];
            link_count[linked] = 0;
        }
        pq.pop();
    }
    return answer;
}