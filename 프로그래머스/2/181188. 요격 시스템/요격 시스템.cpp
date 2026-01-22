#include <string>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(),[](vector<int> a, vector<int> b) -> bool {
        return a[0] < b[0]; 
    });
    
    list<int> not_done;
    multiset<int> ends;
    for(int i = 0 ; i < targets.size() ; ++i)
    {
        not_done.push_back(i);
        ends.insert(targets[i][1]-1);
    }
    
    
    while(!ends.empty())
    {    
        const int i = *(ends.begin());
        for(auto it = not_done.begin() ; it != not_done.end() ;)
        {
            const int start = targets[*it][0], last = targets[*it][1];
            if(i >= start && i < last)
            {               
                ends.erase(ends.equal_range(last-1).first);
                it = not_done.erase(it);
            }
            else if(i < start)
                break;
        }
        ++answer;
    }
    return answer;
}