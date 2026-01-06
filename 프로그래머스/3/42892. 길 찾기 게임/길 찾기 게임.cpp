#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void find_rel(vector<vector<int>>& rel, vector<vector<int>>& nodeinfo, vector<int>& nodes)
{
    vector<vector<int>> side(2,vector<int>());
    for(int i = 1 ; i < nodes.size() ; ++i)
        if(nodeinfo[nodes[i]][0] < nodeinfo[nodes.front()][0])
            side[0].push_back(nodes[i]);
        else 
            side[1].push_back(nodes[i]);
    for(vector<int>& it : side)
        if(!it.empty())
        {
            rel[nodes.front()].push_back(it.front());
            find_rel(rel,nodeinfo,it);
        }
}

void order(vector<vector<int>>& answer, vector<vector<int>>& rel, int parent)
{
    answer[0].push_back(parent+1);
    for(int it : rel[parent])
        order(answer,rel,it);
    answer[1].push_back(parent+1);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2,vector<int>());
    vector<int> nodes;
    for(int i = 0 ; i < nodeinfo.size() ; ++i)
        nodes.push_back(i);
    sort(nodes.begin(), nodes.end(), [nodeinfo](int a, int b){
        if(nodeinfo[a][1] > nodeinfo[b][1]) 
            return true;
        else if(nodeinfo[a][1] == nodeinfo[b][1])
            return nodeinfo[a][0] < nodeinfo[b][0];
        return false;
    });
    vector<vector<int>> rel(nodeinfo.size(),vector<int>());
    find_rel(rel, nodeinfo, nodes);
    order(answer,rel,nodes.front());
    return answer;
}
