#include <queue>
#include <array>
#include <tuple>
#include <vector>

using namespace std;

using T = array<int,2>;

constexpr array<T,4> directions = {{{0,-1},{-1,0},{0,1},{1,0}}};
// 좌, 상, 우, 하
constexpr array<T,4> tile_directions = {{{0,1},{1,2},{2,3},{3,0}}};
// /좌, \우, /우, \좌
constexpr array<T,4> linkable_tiles = {{{1,2},{2,3},{3,0},{0,1}}};
// index 방향일 떄 연결 가능한 타일

int solution(vector<vector<int>> argument_grid) {
    const int N = argument_grid.size(), M = argument_grid[0].size();
    
    vector<vector<T>> grid(N,vector<T>(M));
    vector<vector<T>> visited_in_turn(N,vector<T>(M,{0,0}));
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j)
            if(argument_grid[i][j] == -1)
                grid[i][j] = {1,3};
            else if(argument_grid[i][j] == 1)
                grid[i][j] = {0,2};
    
    int biggest_area = 0;
    int turn = 0;
    
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < M ; ++j)
            for(int k = 0 ; k < 2 ; ++k)
            {
                if(visited_in_turn[i][j][k] != 0)
                    continue;
                ++turn;
                
                int area = 0;
                queue<tuple<int,int,int>> tiles;
                tiles.push({i,j,k});
                while(!tiles.empty())
                {
                    const auto[r,c,idx] = tiles.front();
                    tiles.pop();

                    if(visited_in_turn[r][c][idx] == turn || visited_in_turn[r][c][idx^1] == turn)
                        continue;
                    visited_in_turn[r][c][idx] = turn;
                    ++area;
                    
                    for(const int d : tile_directions[grid[r][c][idx]])
                    {
                        const int nr = r+directions[d][0];
                        const int nc = c+directions[d][1];
                        if(0 > nr || nr >= N
                        || 0 > nc || nc >= M)
                            continue;
                        for(int l = 0 ; l < 2 ; ++l)
                            for(const int lt : linkable_tiles[d])
                                if(lt == grid[nr][nc][l]
                                && visited_in_turn[nr][nc][l] != turn && visited_in_turn[nr][nc][l^1] != turn)
                                    tiles.push({nr,nc,l});
                    }
                }
                
                biggest_area = max(area,biggest_area);
            }
    
    return biggest_area;
}