//2025-09-01 19:59:16
//https://school.programmers.co.kr/learn/courses/30/lessons/120875

#include <string>
#include <vector>
#include <climits>

using namespace std;

double get_leaning(int dx, int dy)
{
    if(dx == 0)
        return INT_MAX;
    return (double)dy/dx;
}

int solution(vector<vector<int>> dots) {
    if(get_leaning(dots[0][0]-dots[1][0],dots[0][1]-dots[1][1]) == get_leaning(dots[2][0]-dots[3][0],dots[2][1]-dots[3][1]))
        return 1;
    if(get_leaning(dots[0][0]-dots[2][0],dots[0][1]-dots[2][1]) == get_leaning(dots[1][0]-dots[3][0],dots[1][1]-dots[3][1]))
        return 1;
    if(get_leaning(dots[0][0]-dots[3][0],dots[0][1]-dots[3][1]) == get_leaning(dots[1][0]-dots[2][0],dots[1][1]-dots[2][1]))
        return 1;
    return 0;
}
