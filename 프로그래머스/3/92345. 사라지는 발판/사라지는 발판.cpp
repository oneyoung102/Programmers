#include <vector>
#include <array>
#include <cmath>

using namespace std;

using Pos = vector<int>;

const array<Pos,4> DIR = {Pos({1,0}),{-1,0},{0,1},{0,-1}};
class Player
{
    public :
        Pos pos;
        Player(Pos&& pos)
            : pos(pos)
        {}
        constexpr inline int operator[](size_t idx) const noexcept
        {
            return pos[idx];
        }
        void move(Pos&& to){pos = std::move(to);}
        void move(const Pos& to){pos = to;}

        bool movable(const vector<vector<int>>& board, const Pos& to) const
        {
            return 0 <= to[0] && to[0] < board.size() && 0 <= to[1] && to[1] < board[0].size()
                && board[to[0]][to[1]] == 1;
        }
};

int dfs(vector<vector<int>>& board, vector<Player>& players, size_t turn)
{
    auto& player = players[turn];
    if(board[player[0]][player[1]] == 0)
        return 0;

    auto prev_pos = player.pos;
    bool has_winning_move = false, movable = false;
    int min_win = 1e9, max_lose = -1;

    board[player[0]][player[1]] = 0;
    for(const auto& dir : DIR)
    {
        Pos npos = {player[0]+dir[0], player[1]+dir[1]};
        if(player.movable(board, npos))
        {
            movable = true;
            player.move(npos);
            const int next_res = dfs(board, players, turn ^ 1);
            player.move(prev_pos);

            if(next_res%2 == 0)
            {
                has_winning_move = true;
                min_win = min(min_win, next_res + 1);
            }
            else
                max_lose = max(max_lose, next_res + 1);
        }
    }
    board[player[0]][player[1]] = 1;

    if(!movable)
        return 0;
    if(has_winning_move)
        return min_win;
    else
        return max_lose;
}
int solution(vector<vector<int>> board, Pos aloc, Pos bloc) {
    vector<Player> players = {Player(std::move(aloc)), Player(std::move(bloc))};
    return dfs(board, players, 0);
}