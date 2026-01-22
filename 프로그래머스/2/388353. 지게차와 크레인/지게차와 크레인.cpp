#include <string>
#include <vector>
#include <map>
#include <deque>

using namespace std;

const vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};

bool detectable(vector<string>& str, vector<vector<bool>>& vis, int i, int j)
{
    vis[i][j] = true;
    if(i == 0 || j == 0 || i == str.size()-1 || j == str[0].size()-1)
        return true;
    for(const pair<int,int> & it : direction)
    {
        int x = i+it.first, y = j+it.second;
        if(str[x][y] == '0' && !vis[x][y] && detectable(str,vis,x,y))
            return true;
    }
    return false;
}

int solution(vector<string> storage, vector<string> requests) {
    int answer = storage.size()*storage[0].size();   
    map<char,deque<pair<int,int>>> container_pos;
    for(int i = 0 ; i < storage.size() ; ++i)
        for(int j = 0 ; j < storage[0].size() ; ++j)
            container_pos[storage[i][j]].push_back({i,j});
    
    deque<pair<int,int>> changed;
    
    for(string it : requests)
    {
        for(int i = 0 ; i < container_pos[it[0]].size() ; ++i) 
        {
            auto p = container_pos[it[0]][i];
                vector<vector<bool>> visited(storage.size(),vector<bool>(storage[0].size(),false));
            if(it.size() == 2 || (it.size() == 1 && detectable(storage,visited,p.first,p.second)))
            {
                changed.push_back({p.first,p.second});
                container_pos[it[0]].erase(container_pos[it[0]].begin()+i--);
                --answer;
            }
        }
        while(!changed.empty())
        {
            storage[changed.front().first][changed.front().second] = '0';
            changed.pop_front();
            
        }
    }   
    return answer;
}