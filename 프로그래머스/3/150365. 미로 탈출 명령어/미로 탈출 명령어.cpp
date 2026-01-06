#include <vector>
#include <string>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    const int cdist = abs(y-c);
    while(x+1 <= n && abs(x+1-r)+cdist <= k-1)
    {
        answer += 'd';
        ++x;
        --k;
    }
    const int rdist = abs(x-r);
    while(y-1 > 0 && rdist+abs(y-1-c) <= k-1)
    {
        answer += 'l';
        --y;
        --k;
    }
    if(y+1 <= m)
    {
        const int rcdist = abs(x-r)+abs(y-c);
        while(rcdist <= k-2)
        {
            answer += 'r';
            answer += 'l';
            k -= 2;
        }
    }
    if(r > x || y > c || x-r+c-y != k)
        return "impossible";
    for(int i = 0 ; i < c-y ; ++i)
        answer += 'r';
    for(int i = 0 ; i < x-r ; ++i)
        answer += 'u';
    return answer;
}