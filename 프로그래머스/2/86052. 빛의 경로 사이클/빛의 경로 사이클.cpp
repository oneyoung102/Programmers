#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    vector<vector<vector<bool>>> visited(grid.size(),vector<vector<bool>>(grid[0].size(),vector<bool>(4,false)));
    //들어가는 4방향(북서남동) 저장
    const int row_size = visited.size(), col_size = visited[0].size();
    for(int i = 0 ; i < row_size ; ++i)
        for(int j = 0 ; j < col_size ; ++j)
            for(int k = 0 ; k < 4 ; ++k)
            {
                int r = i, c = j, d = k;
                int length = 0;
                while(!visited[r][c][d])
                {
                    ++length;
                    visited[r][c][d] = true;
                    if(grid[r][c] == 'S')
                    {
                        if(d == 0)
                            ++r;    
                        else if(d == 1)
                            ++c;
                        else if(d == 2)
                            --r;
                        else if(d == 3)
                            --c;
                    }
                    else if(grid[r][c] == 'L')
                    {
                        if(d == 0)
                            ++c;  
                        else if(d == 1)
                            --r;
                        else if(d == 2)
                            --c;
                        else if(d == 3)
                            ++r;
                        ++d;
                    }
                    else
                    {
                        if(d == 0)
                            --c;  
                        else if(d == 1)
                            ++r;
                        else if(d == 2)
                            ++c;
                        else if(d == 3)
                            --r;
                        --d;
                    }
                    r = (r+row_size)%row_size;
                    c = (c+col_size)%col_size;
                    d = (d+4)%4;
                }
                if(length != 0)
                    answer.push_back(length);
            }
    sort(answer.begin(),answer.end());
    return answer;
}