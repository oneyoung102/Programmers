#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

enum{
    oe_tree,//홀짝트리
    anti_oe_tree,//역홀짝트리
};
vector<unsigned int> GetTreeNumber(unordered_map<unsigned int,unordered_set<unsigned int>>& linked_childs, unordered_map<unsigned int, bool>& visited,unsigned int parent)
{
    vector<unsigned int> TreeNumber(2,0);
    visited[parent]= true;
    ++TreeNumber[(linked_childs[parent].size()+parent)%2];
    for(auto child = linked_childs[parent].begin() ; child != linked_childs[parent].end() ; ++child)
        if(!visited[*child])
        {
            const vector<unsigned int> tn = GetTreeNumber(linked_childs,visited,*child);
            TreeNumber[0] += tn[0];
            TreeNumber[1] += tn[1];
        }
    return TreeNumber;
}
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    unordered_map<unsigned int, bool> visited;// 노드 방문
    unordered_map<unsigned int, unordered_set<unsigned int>> linked_childs; // p의 자식 개수
    //문제에서 edges에 중복 간선 가능하기에 set사용
    for(vector<int>& it : edges) // 부모 노드와 가장 가까운 자식 노드 구하기
    {
        linked_childs[it[0]].insert(it[1]);
        linked_childs[it[1]].insert(it[0]);
    } 
    for(int parent : nodes)//각각의 노드를 부모로 삼은 경우
    {
        if(!visited[parent])
        {
            const vector<unsigned int> tn = GetTreeNumber(linked_childs,visited,parent);
            if(tn[oe_tree] == 1) ++answer[oe_tree];
            if(tn[anti_oe_tree] == 1) ++answer[anti_oe_tree];
        }
    }
    return answer;
}