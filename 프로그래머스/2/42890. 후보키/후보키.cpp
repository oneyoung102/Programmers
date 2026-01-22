#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

bool is_unique(vector<vector<string>>& relation, vector<int>& comb)
{
    map<string,bool> key_checked;
    for(const auto& it : relation)
    {
        string s = "";
        for(const int i : comb)
        {
            s += it[i];
            s += " ";
        }
        if(key_checked[s])
            return false;
        key_checked[s] = true;
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    int keys = 0;
    vector<set<int>> ban;
    queue<vector<int>> combs;
    for(int i = 0 ; i < relation[0].size() ; ++i)
        combs.push({i});
    while(!combs.empty())
    {
        vector<int>& comb = combs.front();
        set<int> comb_set(comb.begin(),comb.end());
        bool is_banned = false;
        for(const auto& s : ban)
            if(includes(comb_set.begin(), comb_set.end(), s.begin(), s.end()))
            {
                is_banned = true;
                break;
            }
        if(!is_banned)
        {
            if(is_unique(relation,comb))
            {
                ban.push_back(comb_set);
                ++keys;
            }
            else
                for(int i = comb.back()+1 ; i < relation[0].size() ; ++i)
                {    
                    comb.push_back(i);
                    combs.push(comb);
                    comb.pop_back();
                }
        }
        combs.pop();
    }
    return keys;
}