#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    enum{none, visited, collide};
    
    int answer = 0;
    int r = 0, c = 0;
    for(vector<int> it : points)
    {
        if(it[0] > r)
            r = it[0];
        if(it[1] > c)
            c = it[1];
    }
    vector<vector<map<int,int>>> trail(r,vector<map<int,int>>(c,map<int,int>()));
    
    for(vector<int> it : routes) 
    {
        int time = 0, i = 1;
        int start_r = points[it[0]-1][0]-1, start_c = points[it[0]-1][1]-1;
        while(true)
        {
            if(trail[start_r][start_c][time] == none)
                trail[start_r][start_c][time] = visited;
            else if(trail[start_r][start_c][time] == visited)
            {
                trail[start_r][start_c][time] = collide;
                ++answer;
            }
            if(start_r == points[it[i]-1][0]-1 && start_c == points[it[i]-1][1]-1)
            {
                ++i;
                if(i == it.size())
                    break;
            }
            if(start_r < points[it[i]-1][0]-1)
                ++start_r;
            else if(start_r > points[it[i]-1][0]-1)
                --start_r;
            else if(start_c < points[it[i]-1][1]-1)
                ++start_c;
            else if(start_c > points[it[i]-1][1]-1)
                --start_c;
            ++time;
        }
    }
    return answer;
}