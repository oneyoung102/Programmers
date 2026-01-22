#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<vector<int>> coord_queen;

void set_queen(int n, int q)
{
    if(q == n)
    {
        ++answer;
        return;
    }
    for(int i = 0 ; i < n ; ++i)
    {
        bool possible = true;
        for(auto& it : coord_queen)
            if(it[0] == i || abs(it[0]-i) == abs(it[1]-q))
            {
                possible = false;
                break;
            }
        if(possible)
        {
            coord_queen.push_back({i,q});
            set_queen(n,q+1);
            coord_queen.pop_back();
        }
    }
    return;
}

int solution(int n) {
    set_queen(n,0);
    return answer;
}