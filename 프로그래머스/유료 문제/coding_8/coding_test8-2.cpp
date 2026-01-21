#include <string>
#include <vector>
#include <map>
#include <climits>

using namespace std;
enum{
    normal, oppose
};

int move(map<int,vector<vector<int>>>& rel, int time, int pos, int n)
{
    static map<int,bool> visited;
    static int min = INT_MAX;
    visited[pos] = true;
    if(pos != n)
    {
        for(vector<int>& it : rel[pos])
            if(!visited[it[0]])
            {
                const int rest = time%(it[1]*2), basictime = it[1];
                int plus;
                if(it[2] == normal)
                    plus = (rest == 0) ? basictime : basictime*3 - rest;
                else
                    plus = (rest == basictime) ? basictime : basictime*2 - rest;
                move(rel,time+plus,it[0],n);
            }
    }
    else if(min > time)
        min = time;
    visited[pos] = false;
    return min;
}

int solution(int n, vector<vector<int>> info) {
    map<int,vector<vector<int>>> rel;
    for(vector<int>& it : info)
    {
        rel[it[0]].push_back({it[1],it[2],normal});
        rel[it[1]].push_back({it[0],it[2],oppose});
    }  
    int answer = move(rel,0,1,n);
    if(answer == INT_MAX)
        return -1;
    else
        return answer;
}
int main()
{
    printf("%d",solution(4,{{1,2,4}, {3,4,2}, {1,3,2}, {2,4,1}}));
    //4,{{1,2,4}, {3,4,2}, {1,3,2}, {2,4,1}}
    //4,{{2,1,4}, {1,3,2}, {3,4,2}, {2,4,1}}
    //4,{{2,1,4}, {1,3,2}, {3,4,2}, {2,4,1}}
    //3,{{1,2,6}}
    return 0;
}
