#include <vector>
#include <queue>

using namespace std;
using T = vector<int>;

int solution(vector<T> maps)
{
    const int m = maps.size()-1, n = maps[0].size()-1;
    const vector<T> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    vector<vector<bool>> visited(m+1,vector<bool>(n+1,false)); 
    visited[0][0] = true;
    queue<T> qc;
    qc.push({0,0,1});
    while(!qc.empty())
    {
        const int r = qc.front()[0], c = qc.front()[1], count = qc.front()[2];
        qc.pop();
        if(r == m && c == n)
            return count;
        for(const T& d : dir)
        {
            const int new_r = r+d[0], new_c = c+d[1];
            if(0 <= new_r && new_r <= m && 0 <= new_c && new_c <= n)
                if(maps[new_r][new_c] == 1 && !visited[new_r][new_c])
                {
                    visited[new_r][new_c] = true;
                    qc.push({new_r,new_c,count+1});
                }
        }      
    }
    return -1;
}