#include <string>
#include <vector>

using namespace std;

int solution(string dirs) {
    const int area = 21;
    vector<vector<bool>> road(area,vector<bool>(area,false));
    int x = 10, y = 10, answer = 0;
    for(const char d : dirs)
    {
        const int before_x = x, before_y = y;
        if(d == 'U' && y+2 < area) y += 2;
        else if(d == 'D' && y-2 >= 0) y -= 2;
        else if(d == 'R' && x+2 < area) x += 2;
        else if(d == 'L' && x-2 >= 0) x -= 2;
        if(before_x != x || before_y != y)
        {
            const int road_x = (before_x+x)/2, road_y = (before_y+y)/2;
            if(!road[road_x][road_y])
            {
                ++answer;
                road[road_x][road_y] = true;
            }
        }     
    }
    return answer;
}