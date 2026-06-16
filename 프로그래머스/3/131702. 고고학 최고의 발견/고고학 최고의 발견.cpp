#include <array>
#include <utility>
#include <vector>

using namespace std;

int answer = 128;
const array<pair<int,int>,5> DIR = {make_pair(1,0),{-1,0},{0,1},{0,-1},{0,0}};
void dfs(vector<vector<int>>&& clockHands, int c, int turn_toal)
{
    const int SIZE = clockHands.size();
    if(c == SIZE)
    {
        vector<vector<int>> new_clockHands = std::move(clockHands);
        int curr_turn_total = 0;
        for(int i = 1 ; i < SIZE ; ++i)
            for(int j = 0 ; j < SIZE ; ++j)
            {
                const int turn_count = 4-new_clockHands[i-1][j];
                if(turn_count == 4)
                    continue;
                for(const auto[dr,dc] : DIR)
                {
                    const int nr = dr+i, nc = dc+j;
                    if(0 <= nr && nr < SIZE && 0 <= nc && nc < SIZE) 
                        new_clockHands[nr][nc] = (new_clockHands[nr][nc]+turn_count)%4;
                }
                curr_turn_total += turn_count;
            }
        int sum = 0;
        for(int i = 0 ; i < SIZE ; ++i)
            for(int j = 0 ; j < SIZE ; ++j)
                sum += new_clockHands[i][j];
        if(sum == 0)
            answer = min(answer,curr_turn_total+turn_toal);
        return;
    }

    for(int turn_count = 0 ; turn_count < 4 ; ++turn_count)
    {
        vector<vector<int>> new_clockHands = clockHands;
        for(const auto[dr,dc] : DIR)
        {
            const int nr = dr, nc = dc+c;
            if(0 <= nr && nr < SIZE && 0 <= nc && nc < SIZE) 
                new_clockHands[nr][nc] = (new_clockHands[nr][nc]+turn_count)%4;
        }
        dfs(std::move(new_clockHands),c+1,turn_toal+turn_count);
    }
}

int solution(vector<vector<int>> clockHands) {
    dfs(std::move(clockHands),0,0);
    return answer;
}