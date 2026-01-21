#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

enum{
    no_ancestor, // 부모의 위 조상 없음
    undefined = 0,// 트리가 정해지지 않음
    oe_tree,//홀짝트리
    anti_oe_tree,//역홀짝트리
    not_both // 어느 트리도 아님
};
unsigned long long make_ud(unsigned int from, unsigned int to)
{
    return ((unsigned long long)from << 20) | to;
}
unsigned int what_type_tree(unordered_map<unsigned int,unordered_set<unsigned int>>& linked_childs, unordered_map<unsigned long long,unsigned int>& several_tree_type,unsigned int parent, unsigned int child)
{
    unsigned int& tree = several_tree_type[make_ud(parent,child)];
    if(tree == undefined)//트리를 탐색한 적 없다면
    {
        tree = ((linked_childs[child].size()-((parent == no_ancestor) ? 0 : 1))+child)%2+oe_tree;

        for(auto it = linked_childs[child].begin() ; it != linked_childs[child].end() ; ++it)
            if(*it != parent)//부모 노드 역행 방지
            {
                if(what_type_tree(linked_childs,several_tree_type,child,*it) != tree)
                {
                    tree = not_both; 
                    several_tree_type[parent] = not_both; //not_both 트리를 포함한 트리의 부모는 not_both
                    return not_both;
                }
            }
    }
    return tree;
}
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    unordered_map<unsigned long long, unsigned int> several_tree_type; // g->p 방향으로 p의 트리 종류
    unordered_map<unsigned int, unordered_set<unsigned int>> linked_childs; // p의 자식 개수
    //문제에서 edges에 중복 간선 가능하기에 set사용
    for(vector<int>& it : edges) // 부모 노드와 가장 가까운 자식 노드 구하기
    {
        linked_childs[it[0]].insert(it[1]);
        linked_childs[it[1]].insert(it[0]);
    } 
    for(int parent : nodes)//각각의 노드를 부모로 삼은 경우
    {
        unsigned int& tree = several_tree_type[parent];
        if(tree == undefined)
        {
            what_type_tree(linked_childs,several_tree_type,no_ancestor,parent);
            if(tree != not_both)
                ++answer[tree-1];
        }
    }
    return answer;
}
int main()
{
    //{11, 9, 3, 2, 4, 6},{{9, 11}, {2, 3}, {6, 3}, {3, 4}}
    //{9, 15, 14, 7, 6, 1, 2, 4, 5, 11, 8, 10},{{5, 14}, {1, 4}, {9, 11}, {2, 15}, {2, 5}, {9, 7}, {8, 1}, {6, 4}}
    vector<int> trees = solution({9, 15, 14, 7, 6, 1, 2, 4, 5, 11, 8, 10},{{5, 14}, {1, 4}, {9, 11}, {2, 15}, {2, 5}, {9, 7}, {8, 1}, {6, 4}});
    printf("%d, %d", trees[0],trees[1]);
    return 0;
}
