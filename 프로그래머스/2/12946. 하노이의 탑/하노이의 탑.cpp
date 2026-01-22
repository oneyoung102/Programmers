#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;

void calc_honoi(int n, int from, int sub, int to)
{
    if(n == 1)
    {
        answer.push_back({from,to});
        return;
    }
    calc_honoi(n-1,from,to,sub);
    answer.push_back({from,to});
    calc_honoi(n-1,sub,from,to);
}

vector<vector<int>> solution(int n) {
    calc_honoi(n,1,2,3);
    return answer;
}