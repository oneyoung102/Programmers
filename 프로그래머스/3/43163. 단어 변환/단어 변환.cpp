#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;

inline bool one_different(const string& begin, const string& target)
{
    int count = 0;
    for(int i = 0 ; i < begin.size() ; ++i)
        if(begin[i] != target[i])
            if(++count >= 2)
                return false;
    return true;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    set<string> words_set(words.begin(),words.end())
;    queue<pair<string,int>> change;
    change.push(make_pair(begin,0));
    while(!change.empty())
    {
        const auto start = change.front();
        if(start.first == target)
        {
            answer = start.second;
            break;
        }
        change.pop();
        for(auto it = words_set.begin() ; it != words_set.end() ;)
            if(one_different(start.first,*it))
            {
                change.push(make_pair(*it,start.second+1));
                it = words_set.erase(it);
            }
            else
                ++it;
    }
    return answer;
}