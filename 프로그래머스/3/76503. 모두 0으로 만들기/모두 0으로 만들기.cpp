#include <string>
#include <vector>

using namespace std;
void explore_tree(long long& answer, vector<long long>& a, vector<vector<int>>& linked, int node, int parent)
{
    for(int c : linked[node])
    {
        if(c == parent)
            continue;
        explore_tree(answer,a,linked,c,node);
        a[node] += a[c];
        answer += abs(a[c]);
        a[c] = 0;
    }
    if(node == 0 && a[node] != 0)
        answer = -1;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long answer = 0;
    vector<vector<int>> linked(a.size(),vector<int>());
    for(vector<int>& e : edges)
    {
        linked[e[0]].push_back(e[1]);
        linked[e[1]].push_back(e[0]);
    }
    vector<long long> add(a.begin(),a.end());
    explore_tree(answer,add,linked,0,-1);
    return answer;
}