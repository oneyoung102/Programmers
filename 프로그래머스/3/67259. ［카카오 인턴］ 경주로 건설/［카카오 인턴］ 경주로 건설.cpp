#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    const int N = board.size();
    vector<vector<vector<int>>> road_cost(N,vector<vector<int>>(N,vector<int>(4,INT_MAX)));
    for(int i = 0 ; i < 4 ; ++i)
        road_cost[0][0][i] = 0;
    const vector<vector<int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    queue<vector<int>> road; road.push({0,0});
    while(!road.empty())
    {
        const int r = road.front()[0], c = road.front()[1];
        road.pop();
        for(int d = 0 ; d < 4; ++d)
        {
            const int nr = r+dir[d][0], nc = c+dir[d][1];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && board[nr][nc] == 0)
            {
                int cost = INT_MAX;
                for(int i = 0 ; i < 4 ; ++i)
                {
                    if(road_cost[r][c][i] == INT_MAX) continue;
                    cost = min(cost,road_cost[r][c][i]+((i == d) ? 100 : 600));
                }
                if(road_cost[nr][nc][d] > cost)
                {
                    road_cost[nr][nc][d] = cost;
                    road.push({nr,nc});
                }
            }
        }
    }
    int answer = INT_MAX;
    for(int i = 0 ; i < 4 ; ++i)
        answer = min(answer,road_cost[N-1][N-1][i]);
    return answer;
}