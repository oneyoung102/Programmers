#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

inline int moving(vector<vector<int>>& link, int pos, int dist)
{
    while(dist < 0)
    {
        pos = link[pos][0];
        ++dist;
    }
    while(dist > 0)
    {
        pos = link[pos][1];
        --dist;
    }
    return pos;
}

string solution(int n, int k, vector<string> cmd) {
    vector<vector<int>> link;
    for(int i = 0 ; i < n ; ++i)
        link.push_back({i-1,i+1});
    stack<int> cut;
    int dist = 0;
    for(const string& command : cmd)
        if(command[0] == 'U')
            dist -= stoi(command.substr(2));
        else if(command[0] == 'D')
            dist += stoi(command.substr(2));
        else
        {
            k = moving(link,k,exchange(dist,0));
            if(command[0] == 'C')
            {
                cut.push(k);
                if(link[k][0] >= 0)
                    link[link[k][0]][1] = link[k][1];
                if(link[k][1] < n)
                    link[link[k][1]][0] = link[k][0];
                k = link[k][(link[k][1] == n) ? 0 : 1];
            }
            else
            {
                const int t = cut.top();
                if(link[t][0] >= 0)
                    link[link[t][0]][1] = t;
                if(link[t][1] < n)
                    link[link[t][1]][0] = t;
                cut.pop();
            }
        }
    string answer(n,'O');
    while(!cut.empty())
    {
        answer[cut.top()] = 'X';
        cut.pop();
    }
    return answer;
}