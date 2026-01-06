#include <vector>

using namespace std;

const int MOD = 20170805;
enum {
    able,
    disable,
    straight
};

constexpr bool is_in_map(int r, int c, int m, int n)
{
    return r < m && c < n;
}

vector<int> get_straight_point(vector<vector<int>>& city_map, int r1, int c1, int r2, int c2)
{
    if(r2 == city_map.size() || c2 == city_map[0].size())
        return {r2,c2};
    if(city_map[r2][c2] == straight)
        return get_straight_point(city_map,r2,c2,2*r2-r1,2*c2-c1);
    return {r2,c2};
}

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[m-1][n-1] = 1;

    for(int i = m-1 ; i >= 0 ; --i)
    {
        for(int j = n-1 ; j >= 0 ; --j)
        {
            if(city_map[i][j] != able)
                continue;
            const vector<vector<int>> point = {{i+1,j},{i,j+1}};
            for(const vector<int> p : point)
            {
                if(is_in_map(p[0],p[1],m,n))
                {
                    if(city_map[p[0]][p[1]] == disable)
                        continue;
                    if(city_map[p[0]][p[1]] == straight)
                    {
                        const vector<int> straight_point = get_straight_point(city_map,p[0],p[1],2*p[0]-i,2*p[1]-j);
                        if(is_in_map(straight_point[0],straight_point[1],m,n))
                            dp[i][j] = (dp[i][j] + dp[straight_point[0]][straight_point[1]])%MOD;
                    }
                    else
                        dp[i][j] = (dp[i][j] + dp[p[0]][p[1]])%MOD;
                }
            }
        }
    }
    return dp[0][0];
}