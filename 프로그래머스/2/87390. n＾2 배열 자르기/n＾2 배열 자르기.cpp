#include <vector>
#include <iostream>

using namespace std;

struct coord
{
    coord(int x, int y){r = x; c = y;};
    int r,c;
};

inline int get_value(int r, int c)
{
    if(c <= r) return r+1;
    return c+1;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    const coord Left(left/n,left%n);
    const coord Right(right/n,right%n);
    
    if(Left.r == Right.r)
    {
        for(int i = Left.c ; i <= Right.c ; ++i)
            answer.push_back(get_value(Left.r,i));
        return answer;
    }
    for(int i = Left.c ; i < n ; ++i)
        answer.push_back(get_value(Left.r,i));
    if(Left.r+1 < Right.r)
        for(int i = Left.r+1 ; i < Right.r ; ++i)
            for(int j = 0 ; j < n ; ++j)
                answer.push_back(get_value(i,j));
    for(int i = 0 ; i <= Right.c ; ++i)
        answer.push_back(get_value(Right.r,i));
    return answer;
}