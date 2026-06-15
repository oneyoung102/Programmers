#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

using Pos = pair<int,int>;
using Figure = vector<Pos>;

const vector<Pos> DIR = {{1,0},{-1,0},{0,1},{0,-1}};

void turn_90(Figure& figure)
{
    for(auto& pos : figure)
    {
        const auto[r,c] = pos;
        pos = {c,-r};
    }
    sort(figure.begin(),figure.end());
    const auto [first_r,first_c] = figure[0];
    for(auto& pos : figure)
    {
        pos.first -= first_r;
        pos.second -= first_c;
    }
}
vector<Figure> get_figures(vector<vector<int>>& grid, int threshold)
{
    const int ignore = threshold^1;
    const int SIZE = grid.size();
    vector<Figure> figures;
    for(int r = 0 ; r < SIZE; ++r)
        for(int c = 0 ; c < SIZE ; ++c)
        {
            if(grid[r][c] == ignore)
                continue;
            Figure figure;
            queue<Pos> coords;
            coords.push({0,0});
            figure.push_back({0,0});
            grid[r][c] = ignore;
            while(!coords.empty())
            {
                const auto[cr,cc] = std::move(coords.front()); // current
                coords.pop();
                const int rr = r+cr, rc = c+cc; // real

                for(const auto[dr,dc] : DIR) // delta
                {
                    const int nr = rr+dr, nc = rc+dc; // new
                    if(0 <= nr && nr < SIZE
                    && 0 <= nc && nc < SIZE
                    && grid[nr][nc] == threshold)
                    {
                        coords.push({cr+dr,cc+dc});
                        figure.push_back({cr+dr,cc+dc});
                        grid[nr][nc] = ignore;
                    }
                }
            }
            sort(figure.begin(),figure.end());
            figures.push_back(std::move(figure));
        }
    return std::move(figures);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    const int SIZE = table.size();

    auto figures = get_figures(table,1);
    auto holes = get_figures(game_board,0);
    int answer = 0;
    for(auto& figure : figures)
    {
        bool fit = false;
        const int BLOCK_COUNT = figure.size();
        for(int i = 0 ; i < 4 ; ++i)
        {
            for(auto& hole : holes)
            {
                if(BLOCK_COUNT != hole.size())
                    continue;

                fit = true;
                for(size_t i = 0 ; i < BLOCK_COUNT ; ++i)
                    if(figure[i] != hole[i])
                    {
                        fit = false;
                        break;
                    }
                    
                if(fit)
                {
                    hole.clear();
                    break;
                }
            }
            if(fit)
                break;
            if(i != 3) //마지막엔 돌릴 필요 없음
                turn_90(figure);
        }
        if(fit)
            answer += BLOCK_COUNT;
    }
    return answer;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ARGUMENTS                ((  	[[1,1,0,0,1,0],[0,0,1,0,1,0],[0,1,1,0,0,1],[1,1,0,1,1,1],[1,0,0,0,1,0],[0,1,1,1,0,0]],[[1,0,0,1,1,0],[1,0,1,0,1,0],[0,1,1,0,1,1],[0,0,1,0,0,0],[1,1,0,1,1,0],[0,1,0,0,0,0]]	  )) // <- 괄호 두 쌍 안에 인수 입력
#define TYPE_OF_ARGUMENTS        vector<vector<int>>, vector<vector<int>>
///////////////////////////// /////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "printFunctionReturn.hpp"
int main()
{
    printFunctionReturn<TYPE_OF_ARGUMENTS>(solution,TO_STRING(ARGUMENTS));
    return 0;
}
