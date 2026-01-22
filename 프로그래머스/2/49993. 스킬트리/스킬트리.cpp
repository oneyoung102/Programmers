#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    vector<bool> exist_skill(26,false);
    for(const char c : skill)
        exist_skill[c-'A'] = true;
    for(const string& s : skill_trees)
    {
        string order = "";
        for(const char c : s)
            if(exist_skill[c-'A'])
                order += c;
        bool possible_tree = true;
        for(int i = 0 ; i < order.size() ; ++i)
            if(skill[i] != order[i])
            {
                possible_tree = false;
                break;
            }
        if(possible_tree)
            ++answer;
    }
    return answer;
}