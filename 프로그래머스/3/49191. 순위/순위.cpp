#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> compete(n);
    for(const auto& r : results)
        compete[r[0]-1].push_back(r[1]-1);
    vector<vector<bool>> compared(n,vector<bool>(n,false));//비교 가능한가
    for(int winner = 0 ; winner < n ; ++winner)
    {
        queue<int> losers;
        for(const int l : compete[winner])
            losers.push(l);
        while(!losers.empty())
        {
            const int loser = losers.front();
            losers.pop();
            if(compared[winner][loser])
                continue;
            compared[winner][loser] = true;
            for(const int l : compete[loser])
                losers.push(l);
        }
    }
    int answer = 0;
    for(int player1 = 0 ; player1 < n ; ++player1)
    {
        bool comparing_possible = true;
        for(int player2 = 0 ; player2 < n ; ++player2)
        {
            if(player1 == player2)
                continue;
            if(!compared[player1][player2] && !compared[player2][player1])
            {
                comparing_possible = false;
                break;
            }
        }
        if(comparing_possible)
            ++answer;
    }
    return answer;
}