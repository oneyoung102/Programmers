#include <vector>
#include <queue>
#include <utility>
#include <cmath>

using namespace std;
using T = pair<int,int>;


bool isIn(int r, int c, int N){return 0 <= r && r < N && 0 <= c && c < N;}
bool isMovable(int h1, int h2, int height){return abs(h1-h2) <= height;}


int solution(vector<vector<int>> land, int height) {
    const int N = land.size();
    const vector<T> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };

    int area_count = 0;
    vector<vector<T>> area_links(N*N);
    vector<vector<int>> area_num(N,vector<int>(N,-1));//사다리 없이 접근 가능한 영역 번호
    for(int i = 0 ; i < N ; ++i)
        for(int j = 0 ; j < N ; ++j)
        {
            if(area_num[i][j] != -1)
                continue;
            const int a1 = area_count;
            queue<T> grids;
            grids.push(make_pair(i,j));
            while(!grids.empty())
            {
                const auto [r,c] = grids.front();
                grids.pop();
                if(area_num[r][c] != -1)
                    continue;
                area_num[r][c] = a1;
                for(const auto [dr,dc] : dir)
                {
                    const int nr = r+dr, nc = c+dc;
                    if(!isIn(nr,nc,N))
                        continue;
                    const int a2 = area_num[nr][nc];
                    if(isMovable(land[r][c],land[nr][nc],height) && a2 == -1)
                        grids.push(make_pair(nr,nc));
                    else if(a2 != -1 && a2 != a1)
                    {
                        const int weight = abs(land[r][c]-land[nr][nc]);
                        area_links[a1].push_back(make_pair(weight,a2));
                        area_links[a2].push_back(make_pair(weight,a1));
                    }  
                }
            }
            ++area_count;
        }
    int answer = 0;//모든 영역을 탐색하기 위한 최소 비용
    vector<bool> area_visited(area_count,false);
    priority_queue<T,vector<T>,greater<T>> areas; // {가중치, 영역 번호}
    areas.push(make_pair(0,0));
    while(!areas.empty())
    {
        const auto [weight,area] = areas.top();
        areas.pop();
        if(area_visited[area])
            continue;
        area_visited[area] = true;
        answer += weight;
        for(const auto [linked_w,linked_a] : area_links[area])
            if(!area_visited[linked_a])
                areas.push(make_pair(linked_w,linked_a));
    }
    return answer;
}