#include <vector>

using namespace std;

enum{
    sheep,
    wolf,
    caught
};

int answer = 0;
vector<int> parents;
void catch_sheeps(vector<int> nodes, int n, int caught_sheeps, int caught_wolves)
{
    answer = max(answer,caught_sheeps);
    for(int i = 1 ; i < nodes.size() ; ++i)
        if(nodes[i] == sheep)
        {
            int n = i, wolf_count = 0;
            while(n != 0)
                if(nodes[n = parents[n]] == wolf)
                    ++wolf_count;
            if(caught_sheeps > caught_wolves+wolf_count)
            {
                vector<int> next_nodes = nodes;
                n = i;
                while(n != 0)
                {
                    next_nodes[n] = caught;
                    n = parents[n];
                }
                catch_sheeps(next_nodes,i,caught_sheeps+1,caught_wolves+wolf_count);
            }
        }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    parents = vector<int>(info.size(),-1);
    for(const auto& n : edges)
        parents[n[1]] = n[0];
    info[0] = caught;
    catch_sheeps(info,0,1,0);
    return answer;
}