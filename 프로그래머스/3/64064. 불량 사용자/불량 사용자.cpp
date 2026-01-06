#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int ban_list_size;
set<string> ban_lists;

void make_combinations(vector<vector<int>>&ban_candidates,vector<bool>& used, string& s)
{
    if(s.size() == ban_list_size)
    {
        ban_lists.insert(s);
        return;
    }
    const auto start = upper_bound(ban_candidates.begin(),ban_candidates.end(), (s.empty()) ? (int)'0' : (int)s.back(), [](int a, vector<int>& b){
        return a < b[0];
    });
    if(start == ban_candidates.end())
        return;
    for(auto it = start ; it < ban_candidates.end() ; ++it)
    {
        const int n = (*it)[0];
        const int idx = (*it)[1];
        if(used[idx])
            continue;
        used[idx] = true;
        s.push_back(n);
        make_combinations(ban_candidates,used,s);
        used[idx] = false;
        s.pop_back();
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    ban_list_size = banned_id.size();
    vector<vector<int>> ban_candidates;
    for(int idx = 0 ; idx < ban_list_size ; ++idx)
        for(int i = 0 ; i < user_id.size() ; ++i)
        {
            if(banned_id[idx].size() != user_id[i].size())
                continue;
            bool same = true;
            for(int j = 0 ; j < ban_list_size ; ++j)
                if(banned_id[idx][j] != '*' && banned_id[idx][j] != user_id[i][j])
                {
                    same = false;
                    break;
                }
            if(same) ban_candidates.push_back({i+'1',idx});
        }
    sort(ban_candidates.begin(),ban_candidates.end(),[](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });

    vector<bool> used(ban_list_size,false);
    string s = "";
    make_combinations(ban_candidates, used, s);
    return ban_lists.size();
}