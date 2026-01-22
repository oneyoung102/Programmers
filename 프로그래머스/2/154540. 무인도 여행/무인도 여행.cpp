#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int food(vector<string>& maps, int x , int y)
{
    int count = maps[x][y] -'0';
    maps[x][y] = 'X';
    if(x+1 < maps.size()&&maps[x+1][y] != 'X')
        count += food(maps,x+1,y);
    if(x>0&&maps[x-1][y] != 'X')
        count += food(maps,x-1,y);
    if(y+1 < maps[0].size()&&maps[x][y+1] != 'X')
        count += food(maps,x,y+1);
    if(y>0&&maps[x][y-1] != 'X')
        count += food(maps,x,y-1);  
    return count;
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    for(int i = 0 ; i< maps.size() ; i++)
        for(int j = 0 ; j < maps[0].size() ; j++)
            if(maps[i][j] == 'X')
                continue;
            else
                answer.push_back(food(maps,i,j));
    if(answer.size()>0)
        sort(answer.begin(), answer.end());
    else
        answer.push_back(-1);
    return answer;
}