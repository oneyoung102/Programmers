#include <string>
#include <vector>
#include <climits>
#include <utility>
#include <queue>

using namespace std;
using coord = pair<int,int>;

int solution(vector<string> maps) {
    coord start, lever, exit;
    for(int i = 0 ; i < maps.size() ; ++i)
        for(int j = 0 ; j < maps[0].size() ; ++j)
        {
            if(maps[i][j] == 'S')
                start = make_pair(i,j);
            else if(maps[i][j] == 'L')
                lever = make_pair(i,j);
            else if(maps[i][j] == 'E')
                exit = make_pair(i,j);
        }


    const int dir[4][2] = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    queue<coord> route;
    route.push(start);
    vector<vector<int>> time(maps.size(),vector<int>(maps[0].size(),INT_MAX));
    time[start.first][start.second] = 0;
    bool to_lever = true;
    while(!route.empty())
    {
        const coord st = route.front();
        route.pop();
        if(to_lever && st == lever)
        {
            const int init_dist = time[lever.first][lever.second];
            time = vector<vector<int>>(time.size(),vector<int>(time[0].size(),INT_MAX));
            time[lever.first][lever.second] = init_dist;
            route = queue<coord>();
            to_lever = false;
        }
        else if(!to_lever && st == exit)
            return time[exit.first][exit.second];
        for(const auto& d : dir)
        {
            const coord dr = make_pair(st.first+d[0],st.second+d[1]);
            if(dr.first >= 0 && dr.first < maps.size() && dr.second >= 0 && dr.second < maps[0].size())
                if(maps[dr.first][dr.second] != 'X' && time[dr.first][dr.second] > time[st.first][st.second]+1)
                {
                    route.push(dr);
                    time[dr.first][dr.second] = time[st.first][st.second]+1;
                }
        }
    }
    return -1;  
}