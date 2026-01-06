#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <climits>
#include <functional>

using namespace std;

bool isOut(int r, int c, int N) {return r < 0 || N <= r || c < 0 || N <= c;}

int solution(vector<vector<int>> board) {
    const int N = 2*board.size()-1;
    vector<vector<int>> B(N,vector<int>(N,1));
    for(int i = 1 ; i < N ; i += 2)
        for(int j = 0 ; j < N ; j += 2)
            B[i][j] = board[(i-1)/2][j/2] + board[(i+1)/2][j/2];
    for(int i = 0 ; i < N ; i += 2)
        for(int j = 1 ; j < N ; j += 2)
            B[i][j] = board[i/2][(j-1)/2] + board[i/2][(j+1)/2];
    for(int i = 1 ; i < N ; i += 2)
        for(int j = 1 ; j < N ; j += 2)
            B[i][j] = board[(i-1)/2][(j-1)/2] + board[(i-1)/2][(j+1)/2] + board[(i+1)/2][(j-1)/2] + board[(i+1)/2][(j+1)/2];
    const vector<pair<int,int>> dir = {
        {0,2},{-2,0},{0,-2},{2,0}
    };
    const auto is_out = bind(isOut,placeholders::_1,placeholders::_2,N);

    vector<vector<int>> times(N,vector<int>(N,INT_MAX));
    times[0][1] = 0;
    queue<tuple<int,int,bool>> drons; //{r,c,degree}, degree : 0도 = 0, 180도 = false 
    drons.push(make_tuple(0,1,true));
    while(!drons.empty())
    {
        const auto [r,c,degree] = drons.front();
        drons.pop();
        if(r == N-2 && c == N-1 || r == N-1 && c == N-2)
            break;
        if(degree)
        {
            for(int i = 0, tr = -1 ; i < 2 ; ++i, tr *= -1)
                if(!is_out(r+tr,c) && B[r+tr][c] == 0)
                {
                    int tc = -1;
                    for(int j = 0 ; j < 2 ; ++j, tc *= -1)
                        if(times[r][c]+1 < times[r+tr][c+tc])
                        {
                            times[r+tr][c+tc] = times[r][c]+1;
                            drons.push(make_tuple(r+tr,c+tc,!degree));
                        }
                }
        }
        else
        {
            for(int i = 0, tc = -1 ; i < 2 ; ++i, tc *= -1)
                if(!is_out(r,c+tc) && B[r][c+tc] == 0)
                {
                    int tr = -1;
                    for(int j = 0 ; j < 2 ; ++j, tr *= -1)
                        if(times[r][c]+1 < times[r+tr][c+tc])
                        {
                            times[r+tr][c+tc] = times[r][c]+1;
                            drons.push(make_tuple(r+tr,c+tc,!degree));
                        }
                }
        }
        for(const auto [dr,dc] : dir)
        {   
            const int nr = r+dr, nc = c+dc;
            if(is_out(nr,nc) || B[nr][nc] != 0)
                continue;
            if(times[r][c]+1 < times[nr][nc])
            {
                times[nr][nc] = times[r][c]+1;
                drons.push(make_tuple(nr,nc,degree));
            }
        }
    }
    return min(times[N-1][N-2],times[N-2][N-1]);
}