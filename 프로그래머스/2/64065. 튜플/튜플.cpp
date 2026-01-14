#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<vector<int>> sets;
    
    string num = "";
    bool insert_mode = false;
    for(int i = 1 ; i < s.size()-1 ; ++i)
        if(s[i] == '{')
        {
            insert_mode = true;
            sets.push_back(vector<int>());
        }
        else if(insert_mode)
        {
            if(s[i] != ',' && s[i] != '}')
                num += s[i];
            else
            {
                sets.back().push_back(stoi(num));
                num = "";
                if(s[i] == '}')
                    insert_mode = false;
            }
        }
    sort(sets.begin(),sets.end(),[](vector<int>& x, vector<int>& y){
        return x.size() < y.size();
    });
    vector<int> answer;
    set<int> checked;
    for(const auto& s : sets)
        for(const int n : s)
            if(checked.find(n) == checked.end())
            {
                answer.push_back(n);
                checked.insert(n);
                break;
            }
    return answer;
}