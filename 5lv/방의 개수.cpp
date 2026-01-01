#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int solution(vector<int> arrows) {
    int answer = 0;
    pair<int,int> pos = {0,0};
    
    map<pair<int,int>,bool> visited;
    map<pair<pair<int,int>,pair<int,int>>,bool> line;
    visited[pos] = true;
    
    const vector<pair<int,int>> direct = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1}}; 
    
    int& pos_x = pos.first;
    int& pos_y = pos.second;
    for(int it : arrows)
    {
        const int dir_x = direct[it].first, dir_y = direct[it].second;
        pos_x += dir_x;
        pos_y += dir_y;
        
        if(!line[{{pos_x-dir_x,pos_y-dir_y},pos}])
        {
            line[{{pos_x-dir_x,pos_y-dir_y},pos}] = true;
            line[{pos,{pos_x-dir_x,pos_y-dir_y}}] = true;
            if(!visited[pos])
                visited[pos] = true;
            else
                ++answer;
            
            if(it%2 == 1)
                if(line[{{pos_x-dir_x,pos_y},{pos_x,pos_y-dir_y}}])
                    ++answer;  
        }
    }
    return answer;
}
