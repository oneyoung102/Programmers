#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer = {-1,0,0,0};
    map<int,int> in, out;
    map<int,bool> checked, eight;
    int point_links = 0;
    
    for(vector<int> it : edges)// 간선 방향 찾기
    {
        ++out[it[0]];
        ++in[it[1]];
    }
    for(int i = 0 ; i < edges.size() ; ++i) //정점 찾기 & 연결 끊기
    {
        if(answer[0] == edges[i][0] || (out[edges[i][0]] >= 2 && in[edges[i][0]] == 0))
        {
            if(answer[0] == -1)
                answer[0] = edges[i][0];
            checked[i] = true;
            --in[edges[i][1]];
            if(in[edges[i][1]]+out[edges[i][1]] == 0)//길이가 1인 직선 찾기
                ++answer[2];
            ++point_links;
        }
    }
    for(int i = 0 ; i < edges.size() ; ++i)
    {
        if(out[edges[i][0]] == 1 && in[edges[i][0]] == 0)//직선 찾기
            ++answer[2];
        else if(out[edges[i][0]] == 2 && in[edges[i][0]] == 2)//8자 찾기
        {
            if(!eight[edges[i][0]])
            {
                ++answer[3];
                eight[edges[i][0]] = true;
            }
            checked[i] = true;
        }
    }
    answer[1] = point_links - answer[2] - answer[3];//도넛 찾기
    return answer;
}