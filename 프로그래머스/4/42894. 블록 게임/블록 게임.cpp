#include <vector>
#include <queue>

using namespace std;

int get_highest_r(int c, vector<vector<int>>& board)
{
    for(int r = 0 ; r < board.size() ; ++r)
        if(board[r][c] != 0)
            return r;
    return board.size()-1;
}
bool fill_able(int r, int c, int block, vector<vector<int>>& board)
{
    if(r < 0)
        return false;
    for(int i = -2 ; i <= 2 ; ++i)
        if(0 <= c+i && c+i < board.size() && board[r][c+i] == block)
            return true;
    return false;
}

int solution(vector<vector<int>> board) {
    vector<int> block_fill_count(201,0);//1,2,3,...,200
    const vector<vector<int>> dir = {
        {1,0},{-1,0},{0,1},{0,-1}
    };
    int answer = 0, c = 0;
    while(c < board.size())
    {
        const int highest_r = get_highest_r(c,board), highest_block = board[highest_r][c];
        if(highest_block == 0)
        {
            ++c;
            continue;
        }
        if(fill_able(highest_r-1,c,highest_block,board))
        {
            ++block_fill_count[highest_block];
            board[highest_r-1][c] = highest_block;
            if(block_fill_count[highest_block] == 1 && fill_able(highest_r-2,c,highest_block,board))
            {
                ++block_fill_count[highest_block];
                board[highest_r-2][c] = highest_block;
            }
        }
        else
        {
            ++c;
            continue;
        }
        if(block_fill_count[highest_block] == 2)
        {
            queue<vector<int>> rcs; //{r,c}
            rcs.push({highest_r,c});
            while(!rcs.empty())
            {
                const int r = rcs.front()[0], c = rcs.front()[1];
                rcs.pop();
                if(board[r][c] == highest_block)
                    board[r][c] = 0;
                for(const auto& d : dir)
                {
                    const int nr = r+d[0], nc = c+d[1];
                    if(0 <= nr && nr < board.size() && 0 <= nc && nc < board.size() && board[nr][nc] == highest_block)
                        rcs.push({nr,nc});
                }
            }
            ++answer;
            c = max(c-2,0);
        }
        else
            ++c;
    }
    return answer;
}