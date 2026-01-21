#include <string>
#include <vector>
 
using namespace std;
void heater(vector<vector<long long>>& answer, int x, int y,  int n, int m)
{
    int dir_x[4] = {1,0,-1,0};
    int dir_y[4] = {0,1,0,-1};
    int minute = 0;
    int i = 0, count = 0, move = -1;
    int pos_x = x-1, pos_y = y-1;
    while(count < n*n)
    {
        if(m-minute != 0)
        {
            if(pos_x < n && pos_x >= 0 && pos_y < n && pos_y >=0)
            {
                answer[pos_x][pos_y] += m-minute;
                ++count;
            }
        }
        else
            break;
        if(i!=0)
        {
            pos_x += dir_x[move%4];
            pos_y += dir_y[move%4];
        }
        if(i%((2*minute+3)*(2*minute+3)-1) == 0)
        {
            pos_x -= 1;
            pos_y -= 1;
            if(i!=0)
                ++minute;
        }
        if((i-(2*minute+1)*(2*minute+1)+1)%(2*minute+2) == 0)
            ++move;
        ++i;
    }
}
void cooler(vector<vector<long long>>& answer, int x, int y,  int n, int m)
{
    int dir_x[4] = {1,-1,-1,1};
    int dir_y[4] = {1,1,-1,-1};
    int minute = 0, sum = 0;
    int i = 0, count = 0, move = -1;
    int pos_x = x-1, pos_y = y-1;
    while(count < n*n)
    {
        if(m-minute != 0)
        {
            if(pos_x < n && pos_x >= 0 && pos_y < n && pos_y >=0)
            {
                answer[pos_x][pos_y] -= (m-minute);
                ++count;
            }
        }
        else
            break;
        if(i!=0)
        {
            pos_x += dir_x[move%4];
            pos_y += dir_y[move%4];
        }
        if((i+1)%(sum+4*minute+4)== 0 || i == 0)
        {
            pos_y -= 1;
            if(i!=0)
                ++minute;
            sum = i+1;
        }
        if(pos_x == x-1 || pos_y == y-1)
            ++move;
        ++i;
    }
}
vector<vector<long long>> solution(int n, int m, vector<vector<int>> fires, vector<vector<int>> ices) {
    vector<vector<long long>> answer(n,vector<long long>(n,0));
    for(vector<int> i : fires)
        heater(answer,i[0],i[1],n,m);
    for(vector<int> i : ices)
        cooler(answer,i[0],i[1],n,m);
    return answer;
}
int main()
{
    for(vector<long long> i : solution(5,3, {{5, 5}, {1, 3}, {5, 2}}, {{1, 5}, {3, 2}}))
    {
        for(long long j : i)
            printf("%lld ", j);
        printf("\n");
    }
}