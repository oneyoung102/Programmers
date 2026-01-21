#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

class GetTree {
    public :
        GetTree(vector<int>& n, vector<vector<int>>& e) : nodes(n), edges(e)
        {
            for(vector<int>& it : e) // 부모 노드와 가장 가까운 자식 노드 구하기
            {
                linked_childs[it[0]].insert(it[1]);
                linked_childs[it[1]].insert(it[0]);
            }
        }
        ~GetTree(){}

        void GetAnswer(vector<int>& answer)
        {
            for(int ancestor : nodes)
            {
                if(several_tree_type[ancestor] == undefined)
                    ++answer[GetWhatTree(ancestor)-1];
                else if(several_tree_type[ancestor] != not_both)
                    ++answer[several_tree_type[ancestor]-1];
            }
        }
    private :
        enum{
            no_ancestor = 0, // 자식 없음
            undefined = 0,// 트리가 정해지지 않음
            oe_tree,//홀짝트리
            anti_oe_tree,//역홀짝트리
            not_both // 어느 트리도 아님
        };
        vector<int> nodes; vector<vector<int>> edges;
        unordered_map<unsigned long long, unsigned int> several_tree_type; // g->p 방향으로 p의 트리 종류
        unordered_map<unsigned int, unordered_set<unsigned int>> linked_childs; // p의 자식 개수
        //문제에서 edges에 중복 간선 가능하기에 set사용

        unsigned long long make_ud(unsigned int from, unsigned int to)
        {
            return ((unsigned long long)from << 20) | to;
        }

        unsigned int GetWhatTree(unsigned int ancestor)
        {
            stack<vector<unsigned int>> parent_route;
            parent_route.push({ancestor,no_ancestor,no_ancestor});
            several_tree_type[ancestor] = (linked_childs[ancestor].size()+ancestor)%2 + oe_tree;
            while(!parent_route.empty())
            {
                const unsigned int parent = parent_route.top()[0], g_parent = parent_route.top()[1], gg_parent = parent_route.top()[2];

                parent_route.pop();
                for(auto child = linked_childs[parent].begin() ; child != linked_childs[parent].end() ; ++child)
                    if(*child != g_parent)
                    {
                        parent_route.push({*child,parent,g_parent});
                        unsigned int& sst = several_tree_type[make_ud(parent,*child)];
                        if(sst == undefined)
                            sst = (linked_childs[*child].size()-1+*child)%2 + oe_tree;
                        else if(sst == not_both)
                            return several_tree_type[ancestor] = not_both;
                    }
                if(parent != ancestor)
                {
                    const unsigned long long ud_1 = make_ud(g_parent,parent), ud_2= make_ud(gg_parent,g_parent);  
                    if(several_tree_type[ud_1] != several_tree_type[ud_2])
                    {
                        several_tree_type[ud_2] = not_both;
                        several_tree_type[gg_parent] = not_both;
                        return several_tree_type[ancestor] = not_both;
                    }  
                } 
            }
            return several_tree_type[ancestor];
        }

};
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer(2,0);
    GetTree gettree(nodes,edges);
    gettree.GetAnswer(answer);
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
