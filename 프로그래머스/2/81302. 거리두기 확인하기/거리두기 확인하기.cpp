#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    const int limit_dist = 2;
    const vector<vector<int>> dir = {{0,1},{1,0},{0,-1}};
    for(const auto& place : places)
    {
        bool impossible = false;
        for(int i = 0 ; i < place.size() ; ++i)
        {
            for(int j = 0 ; j < place[0].size() ; ++j)
            {
                if(place[i][j] != 'P')
                    continue;
                queue<vector<int>> coords;
                coords.push({i,j});
                vector<vector<int>> memo(place.size(),vector<int>(place[0].size(),false));
                memo[i][j] = true;
                while(!coords.empty())
                {
                    const vector<int> coord = coords.front();
                    coords.pop();
                    for(const auto& d : dir)
                    {
                        const int r = coord[0]+d[0], c = coord[1]+d[1];
                        if(r >= 0 && c >= 0 && r < place.size() && c < place[0].size() && !memo[r][c] && abs(r-i)+abs(c-j) <= limit_dist)
                        {
                            memo[r][c] = true;
                            if(place[r][c] == 'O')
                                coords.push({r,c});
                            else if(place[r][c] == 'P')
                            {
                                impossible = true;
                                break;
                            }
                        }
                    }
                    if(impossible)
                        break;
                }
                if(impossible)
                    break;
            }
            if(impossible) 
                break;
        }
        if(impossible)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
            
    return answer;
}