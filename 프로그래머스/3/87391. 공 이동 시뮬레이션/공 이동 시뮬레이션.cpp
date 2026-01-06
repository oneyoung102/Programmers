#include <vector>

using namespace std;

bool moving_front(int& p1, int& p2, int dx, int upper)
{
    if(p1+dx < upper)
    {
        p2 += (p2 == 0) ? 0 : dx;
        p1 += dx;
    }
    else if(p2+dx < upper)
    {
        p2 += (p2 == 0) ? 0 : dx;
        p1 = upper-1;
    }
    else if(p2 == 0)
        p1 = upper-1;
    else
        return false;
    return true;
}
bool moving_back(int& p1, int& p2, int dx, int upper)
{
    if(p2-dx >= 0)
    {
        p2 -= dx;
        p1 -= (p1 == upper-1) ? 0 : dx;
    }
    else if(p1-dx >= 0)
    {
        p2 = 0;
        p1 -= (p1 == upper-1) ? 0 : dx;
    }
    else if(p1 == upper-1)
        p2 = 0;
    else
        return false;
    return true;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    int left_dr = x, right_dr = x, left_dc = y, right_dc = y;
    for(auto it = queries.rbegin() ; it < queries.rend() ; ++it)
    {
        const int command = (*it)[0], dx = (*it)[1];
        if(command == 0)
        {
            if(!moving_front(right_dc,left_dc,dx,m))
                return 0;
        }
        else if(command == 1)
        {
            if(!moving_back(right_dc,left_dc,dx,m))
                return 0;
        }
        else if(command == 2)
        {
            if(!moving_front(right_dr,left_dr,dx,n))
                return 0;
        }
        else if(command == 3)
        {
            if(!moving_back(right_dr,left_dr,dx,n))
                return 0;
        }
    }
    return (long long)(right_dr-left_dr+1)*(right_dc-left_dc+1);
}