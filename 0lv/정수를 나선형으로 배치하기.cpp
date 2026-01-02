//2024-12-31 09:12:55
//https://school.programmers.co.kr/learn/courses/30/lessons/181832

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n,vector<int>(n,0));
    int xmove[4] = {1,0,-1,0};
    int ymove[4] = {0,1,0,-1};
    int xpos = 0, ypos = 0;
    for(int i = 0,mode = 0 ; i < n*n ; i++)
    {
        answer[ypos][xpos] = i+1;
        xpos+=xmove[mode%4];
        ypos+=ymove[mode%4];
        if(xpos+xmove[mode%4]<0||ypos+ymove[mode%4]<0||xpos+xmove[mode%4]>=n||ypos+ymove[mode%4]>=n||answer[ypos+ymove[mode%4]][xpos+xmove[mode%4]]!=0)
            mode+=1;
    }
    return answer;
}
