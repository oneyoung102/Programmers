#include <vector>
#include <stack>
#include <cmath>

using namespace std;

constexpr bool is_in_picture(int r, int c, int m, int n)
{
    return r >= 0 && r < m && c >= 0 && c < n;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    const vector<vector<int>> four_dir = {
        {0,1},{0,-1},{1,0},{-1,0}
    };

    vector<vector<bool>> visited(m,vector<bool>(n,false));
    for(int i = 0 ; i < m ; ++i)
    {
        for(int j = 0 ; j < n ; ++j)
        {
            if(visited[i][j] || picture[i][j] == 0)
                continue;

            ++number_of_area;

            stack<vector<int>> close_points;
            close_points.push({i,j});
            visited[i][j] = true;

            int size_of_one_area = 1;
            while(!close_points.empty())
            {
                const vector<int> point = close_points.top();
                close_points.pop();
                for(vector<int> fd : four_dir)
                {
                    const int r = point[0]+fd[0], c = point[1]+fd[1];
                    if(is_in_picture(r,c,m,n) && !visited[r][c] && picture[r][c] == picture[i][j])
                    {
                        visited[r][c] = true;
                        close_points.push({r,c});
                        ++size_of_one_area;
                    }
                }
            }
            max_size_of_one_area = max(max_size_of_one_area,size_of_one_area);
        }
    }
    return {number_of_area,max_size_of_one_area};
}