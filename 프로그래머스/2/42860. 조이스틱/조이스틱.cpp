#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
void find_case(vector<int>& cases, vector<vector<int>>& dis, vector<int>& poss, string& name, int total, int pos)
{    
    if(poss.empty())
        cases.push_back(total);
    for(int i : poss)
    {
        if(name[i] != 'A')
        {
            vector<int> sub;
            for(int j : poss)
                if(j != i)
                    sub.push_back(j);
            find_case(cases,dis,sub,name,total+dis[i][pos], i);
        }
    }
}
int solution(string name) {
    vector<int> cases;
    
    vector<vector<int>> distance(name.size(),vector<int>(name.size(),-1));
    for(int i = 0 ; i < distance.size() ; ++i)
        for(int j = 0 ; j < distance[0].size() ; ++j)
            distance[i][j] = min(name[i]-'A', 'Z'- name[i] + 1)+min(abs(i-j), int(name.size()) -abs(i-j));
    
    vector<int> poss;
    for(int i = 1 ; i < name.size() ; ++i)
        if(name[i] != 'A')
            poss.push_back(i);
    
    const int start = min(name[0]-'A','Z'-name[0]+1);
    find_case(cases,distance,poss,name,start,0);
    return *min_element(cases.begin(),cases.end());
}

int main()
{
    printf("%d, %d",solution("JEROEN"), solution("JAZ"));
    return 0;
}