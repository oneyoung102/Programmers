#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <utility>

using namespace std;

vector<string> solution(vector<string> record) {
    map<string,string> name_id;
    vector<pair<string,char>> log;
    for(const string& r : record)
    {
        string act, id, name;
        stringstream ss(r);
        ss >> act >> id >> name;
        if(act != "Leave")
            name_id[id] = name;
        if(act != "Change")
            log.push_back(make_pair(id,act[0]));
    }
    vector<string> answer;
    for(const auto& l : log)
    {
        if(l.second == 'E')
            answer.push_back(name_id[l.first]+"님이 들어왔습니다.");
        else
            answer.push_back(name_id[l.first]+"님이 나갔습니다.");
    }
    return answer;
}