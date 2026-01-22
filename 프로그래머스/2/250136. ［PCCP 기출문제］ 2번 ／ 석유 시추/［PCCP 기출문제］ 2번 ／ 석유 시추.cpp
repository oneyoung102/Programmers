#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
using coord = pair<int,int>;

int solution(vector<vector<int>> land) {
    int max_coal = 0;
    
    vector<int> ground(land[0].size(),0);
    const int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    for(int i = 0 ; i < land.size() ; ++i)
    {
        for(int j = 0 ; j < land[0].size() ; ++j)
        {
            if(land[i][j] == 0)
                continue;
            
            queue<coord> coords;
            coords.push(make_pair(i,j));
            land[i][j] = 0;
            
            int min_c = j, max_c = j, coal = 1;
            while(!coords.empty())
            {
                const coord& cd = coords.front();
                for(const auto& d : dir)
                {
                    const int r = cd.first+d[0], c = cd.second+d[1];
                    if(0 <= r && r < land.size() && 0 <= c && c < land[0].size() && land[r][c] == 1)
                    {
                        coords.push(make_pair(r,c));
                        ++coal;
                        land[r][c] = 0;
                        min_c = min(min_c,c);
                        max_c = max(max_c,c);
                    }
                }
                coords.pop();
            }
            for(int k = min_c ; k <= max_c ; ++k)
            {
                ground[k] += coal;
                max_coal = max(max_coal,ground[k]);
            }
        }
    }
    return max_coal;
}