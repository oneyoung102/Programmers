#include <vector>
#include <queue>
#include <functional>

using namespace std;

bool line_able(vector<vector<bool>>& lines, vector<vector<int>>& rectangles, int x, int y)
{
    if(lines[x][y])
        return true;
    for(const auto& rectangle : rectangles)
    {
        const int lX = 2*rectangle[0]-2, lY = 2*rectangle[1]-2, rX = 2*rectangle[2]-2, rY = 2*rectangle[3]-2;
        if(lX < x && x < rX && lY < y && y < rY)
            return false;
    }
    return true;
}

int solution(vector<vector<int>> rectangles, int characterX, int characterY, int itemX, int itemY) {
    vector<vector<bool>> lines(99,vector<bool>(99,false));
    auto is_line_able = bind(line_able,ref(lines),ref(rectangles),placeholders::_1,placeholders::_2);

    for(const auto& rectangle : rectangles)
    {
        const int lX = 2*rectangle[0]-2, lY = 2*rectangle[1]-2, rX = 2*rectangle[2]-2, rY = 2*rectangle[3]-2;
        for(int i = lX+1 ; i <= rX-1 ; i += 2)
        {
            lines[i][lY] = is_line_able(i,lY);
            lines[i][rY] = is_line_able(i,rY);
        }
        for(int i = lY+1 ; i <= rY-1 ; i += 2)
        {
            lines[lX][i] = is_line_able(lX,i);
            lines[rX][i] = is_line_able(rX,i);
        }
    }

    const vector<vector<int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    queue<vector<int>> trail;
    trail.push({characterX,characterY,0});
    while(!trail.empty())
    {
        const int X = trail.front()[0], Y = trail.front()[1], dist = trail.front()[2];
        if(X == itemX && Y == itemY)
            return dist;
        trail.pop();
        for(const auto d : dir)
        {
            const int newX = X+d[0], newY = Y+d[1];
            if(0 < newX && newX <= 50 && 0 < newY && newY <= 50 && lines[X+newX-2][Y+newY-2])
            {
                lines[X+newX-2][Y+newY-2] = false;
                trail.push({newX,newY,dist+1});
            }
        }
    }
    return -1;
}