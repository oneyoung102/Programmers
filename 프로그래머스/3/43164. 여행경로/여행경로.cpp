#include <string>
#include <vector>
#include <map>
#include <set>
#include <utility>

using namespace std;

bool complete = false;
int total_visit = 1;
vector<string> answer = {"ICN"};
map<string,multiset<string>> airports;
void travel(int visit)
{
    if(visit == total_visit)
        complete = true;
    const string broad = answer.back();
    for(auto it = airports[broad].begin() ; !complete && it != airports[broad].end() ;)
    {
        const string temp = *it;
        it = airports[broad].erase(it);
        answer.push_back(temp);
        travel(visit+1);
        if(!complete)
        {
            airports[broad].insert(temp);
            answer.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for(const auto& t : tickets)
        airports[t[0]].insert(t[1]);
    total_visit = tickets.size();
    travel(0);
    return answer;
}