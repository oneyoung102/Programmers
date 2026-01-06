#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {\
    const int members = id_list.size();
    vector<int> answer(members,0);
    map<string,int> numbering;
    vector<int> reported(members,0);
    vector<vector<bool>> reporting(members,vector<bool>(members,false));
    for(int i = 0 ; i < members ; ++i)
        numbering[id_list[i]] = i;
    
    auto get_name = [&numbering](string s)-> pair<int,int>{
        for(int i = 0 ; i < s.size() ; ++i)
            if(s[i] == ' ')
                return {numbering[s.substr(0,i)],numbering[s.substr(i+1)]};
    };
    
    for(string& it : report)
    {
        auto rel = get_name(it);
        if(!reporting[rel.first][rel.second])
        {
            ++reported[rel.second];
            reporting[rel.first][rel.second] = true;
        }
    }
    for(int i = 0 ; i < members ; ++i)
        for(int j = 0 ; j < members ; ++j)
            if(reported[j] >= k && reporting[i][j])
                ++answer[i];
    return answer;
}