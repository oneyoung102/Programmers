#include <vector>
#include <queue>
#include <utility>

using namespace std;

int ctrl(int r, int c, int type, vector<vector<int>>& b)
{
    int dist = 0;
    do
    {
        if(type == 0)
        {
            if(r == 3)
                break;
            ++r;
        }
        else if(type == 1)
        {
            if(c == 0)
                break;
            --c;
        }
        else if(type == 2)
        {
            if(r == 0)
                break;
            --r;
        }
        else if(type == 3)
        {
            if(c == 3)
                break;
            ++c;
        }
        ++dist;
    }
    while(b[r][c] == 0);
    return dist;
}
int get_cost(int from_r, int from_c, int to_r, int to_c, vector<vector<int>>& b)
{
    vector<vector<bool>> visited(4,vector<bool>(4,false));
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq; //{cost,r,c};
    pq.push({0,from_r,from_c});
    while(!pq.empty())
    {
        const int costs = pq.top()[0], curr_r = pq.top()[1], curr_c = pq.top()[2];
        if(curr_r == to_r && curr_c == to_c)
            break;
        pq.pop();
        if(visited[curr_r][curr_c])
            continue;
        visited[curr_r][curr_c] = true;
        if(curr_r < 3) pq.push({costs+1,curr_r+1,curr_c});
        if(curr_r > 0) pq.push({costs+1,curr_r-1,curr_c});
        if(curr_c < 3) pq.push({costs+1,curr_r,curr_c+1});
        if(curr_c > 0) pq.push({costs+1,curr_r,curr_c-1});
        pq.push({costs+1,curr_r+ctrl(curr_r,curr_c,0,b),curr_c});
        pq.push({costs+1,curr_r-ctrl(curr_r,curr_c,2,b),curr_c});
        pq.push({costs+1,curr_r,curr_c+ctrl(curr_r,curr_c,3,b)});
        pq.push({costs+1,curr_r,curr_c-ctrl(curr_r,curr_c,1,b)});
    }
    return pq.top()[0];
}

void calc_possiblity(vector<bool>& numbers, vector<int>& possiblity, vector<vector<int>>& possiblities)
{
    if(possiblity.size() == numbers.size())
    {
        possiblities.push_back(possiblity);
        return;
    }
    for(int i = 0 ; i < numbers.size() ; ++i)
    {
        if(!numbers[i])
            continue;
        numbers[i] = false;
        possiblity.push_back(i);
        calc_possiblity(numbers,possiblity,possiblities);
        numbers[i] = true;
        possiblity.pop_back();
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    vector<vector<vector<int>>> blocks(6);
    for(int i = 0 ; i < 4 ; ++i)
        for(int j = 0 ; j < 4 ; ++j)
            if(board[i][j] != 0)
                blocks[board[i][j]-1].push_back({i,j});

    vector<vector<int>> possiblities;
    vector<bool> numbers(6,true);
    vector<int> possiblity;
    calc_possiblity(numbers,possiblity,possiblities);

    int min_costs = 1000000;
    for(const auto& poss : possiblities)
    {
        vector<vector<int>> b = board;
        queue<vector<int>> q; //{cost,r,c};
        q.push({0,r,c});
        for(const int block : poss)
        {
            if(blocks[block].empty())
                continue;
            const int count = q.size();
            for(int i = 0 ; i < count ; ++i)
            {
                const int costs = q.front()[0], curr_r = q.front()[1], curr_c = q.front()[2];
                q.pop();
                if(costs >= min_costs)
                    continue;
                const int r0 = blocks[block][0][0], c0 = blocks[block][0][1], r1 = blocks[block][1][0], c1 = blocks[block][1][1];
                const int cost0 = get_cost(curr_r,curr_c,r0,c0,b)+get_cost(r0,c0,r1,c1,b), cost1 = get_cost(curr_r,curr_c,r1,c1,b)+get_cost(r1,c1,r0,c0,b);
                if(cost1 <= cost0)
                    q.push({costs+cost1+2,r0,c0});
                if(cost1 >= cost0)
                    q.push({costs+cost0+2,r1,c1});
                b[r0][c0] = 0;
                b[r1][c1] = 0;
            }
        }
        while(!q.empty())
        {
            min_costs = min(min_costs,q.front()[0]);
            q.pop();
        }
    }
    return min_costs;
}