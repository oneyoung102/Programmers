#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class ricochet
{
    private :
        const vector<string> board;

        struct pos{int r, c;};
        pos goal, init;
        void find_goal_start();
        int search_board();


    public :
        ricochet(vector<string>& b) : board(b){};
        int get_answer();
};
void ricochet::find_goal_start()
{
    goal.r = -1;
    init.r = -1;
    for(int i = 0 ; i < board.size() ; ++i)
        for(int j = 0 ; j < board[0].size() ; ++j)
        {
            if(goal.r != -1 && init.r != -1)
                return;
            if(board[i][j] == 'G')
            {
                goal.r = i;
                goal.c = j;
            }
            else if(board[i][j] == 'R')
            {
                init.r = i;
                init.c = j;
            }
        }
}
int ricochet::search_board()
{
    vector<vector<int>> min_dists(board.size(),vector<int>(board[0].size(),INT_MAX));
    min_dists[init.r][init.c] = 0;
    queue<pos> dist;
    dist.push(init);
    while(!dist.empty())
    {
        const pos start = dist.front();
        if(start.r == goal.r && start.c == goal.c)
            break;
        dist.pop();
        for(int i = start.c+1 ; i <= board[0].size() ; ++i)
            if(i == board[0].size() || board[start.r][i] == 'D')
            {
                if(min_dists[start.r][i-1] > min_dists[start.r][start.c]+1)
                {
                    min_dists[start.r][i-1] = min_dists[start.r][start.c]+1;
                    dist.push({start.r,i-1});
                }
                break;
            }
        for(int i = start.c-1 ; i >= -1 ; --i)
            if(i == -1 || board[start.r][i] == 'D')
            {
                if(min_dists[start.r][i+1] > min_dists[start.r][start.c]+1)
                {
                    min_dists[start.r][i+1] = min_dists[start.r][start.c]+1;
                    dist.push({start.r,i+1});
                }
                break;
            }
        for(int i = start.r+1 ; i <= board.size() ; ++i)
            if(i == board.size() || board[i][start.c] == 'D')
            {
                if(min_dists[i-1][start.c] > min_dists[start.r][start.c]+1)
                {
                    min_dists[i-1][start.c] = min_dists[start.r][start.c]+1;
                    dist.push({i-1,start.c});
                }
                break;
            }
        for(int i = start.r-1 ; i >= -1 ; --i)
            if(i == -1 || board[i][start.c] == 'D')
            {
                if(min_dists[i+1][start.c] > min_dists[start.r][start.c]+1)
                {
                    min_dists[i+1][start.c] = min_dists[start.r][start.c]+1;
                    dist.push({i+1,start.c});
                }
                break;
            }
    }
    return min_dists[goal.r][goal.c];
}

int ricochet::get_answer()
{
    find_goal_start();
    const int answer = search_board();
    if(answer == INT_MAX)
        return -1;
    return answer;
}

int solution(vector<string> board) {
    ricochet RC(board);
    return RC.get_answer();
}