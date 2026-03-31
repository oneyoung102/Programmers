#include <vector>
#include <utility>

using namespace std;

const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
const vector<pair<int,int>> dirs = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
const vector<vector<vector<int>>> linkable_rail = {
    {{2,UP},{3,UP},{6,RIGHT},{7,LEFT}},
    {{1,RIGHT},{3,RIGHT},{4,UP},{7,DOWN}},
    {{2,DOWN},{3,DOWN},{4,LEFT},{5,RIGHT}},
    {{1,LEFT},{3,LEFT},{5,UP},{6,DOWN}}
};
struct Pos
{
    int r;
    int c;
    int dir;
    Pos(int r, int c, int dir)
    {
        this->r = r;
        this->c = c;
        this->dir = dir;
    }
    bool operator==(const Pos& other) const
    {
        return r == other.r && c == other.c && dir == other.dir;
    }
};

class Train
{
    private : 
        int answer;
        const int m, n;
        vector<vector<int>> grid;
        vector<vector<bool>> visit_point;
        const Pos destination;

        bool is_out(const Pos& pos)
        {
            return 0 > pos.r || pos.r >= m || 0 > pos.c || pos.c >= n;
        }
        
    public :
        Train(const vector<vector<int>> grid, const Pos destination)
            : m(grid.size())
            , n(grid[0].size())
            , destination(destination)
        {
            answer = 0;
            this->grid = grid;
            visit_point = vector<vector<bool>>(m,vector<bool>(n,false));
            for(int i = 0 ; i < m ; ++i)
                for(int j = 0 ; j < n ; ++j)
                    visit_point[i][j] = (grid[i][j] != -1 && grid[i][j] != 0);
        }

        void move_train(const Pos pos, int cross, int visit)
        {
            if(is_out(pos))
                return;
            const bool prev_visit = visit_point[pos.r][pos.c];
            if(visit_point[pos.r][pos.c])
            {
                visit_point[pos.r][pos.c] = false;
                --visit;
            }
            if(pos == destination && cross == 0 && visit == 0)
            {
                ++answer;
                visit_point[pos.r][pos.c] = prev_visit;
                return;
            }
            const int curr_rail = grid[pos.r][pos.c];
            if(curr_rail == 0)
                for(const auto& new_rail : linkable_rail[pos.dir])    
                {
                    grid[pos.r][pos.c] = new_rail[0];
                    const auto[dr,dc] = dirs[new_rail[1]];
                    const Pos npos (pos.r+dr,pos.c+dc,new_rail[1]);
                    move_train(npos,cross+(int)(new_rail[0] == 3),visit);
                    grid[pos.r][pos.c] = 0;
                }
            else if(curr_rail != -1)
                for(const auto& candi_rail : linkable_rail[pos.dir])
                    if(curr_rail == candi_rail[0])
                    {
                        const auto[dr,dc] = dirs[candi_rail[1]];
                        const Pos npos (pos.r+dr,pos.c+dc,candi_rail[1]);
                        move_train(npos,cross-(int)(candi_rail[0] == 3),visit);
                        break;
                    }
            visit_point[pos.r][pos.c] = prev_visit;
        }
        int get_answer(){return answer;}
};
int solution(vector<vector<int>> grid) {
    const int m = grid.size(), n = grid[0].size();
    const int dir = (grid[m-1][n-1] == 1) ? RIGHT : DOWN;
    int cross = 0, visit = 0;
    for(int i = 0 ; i < m ; ++i)
        for(int j = 0 ; j < n ; ++j)
        {
            if(grid[i][j] == 3)
                cross += 2;
            if(grid[i][j] != -1 && grid[i][j] != 0)
                ++visit;
        }
    Train train(grid,Pos(m-1,n-1,dir));
    train.move_train(Pos(0,0,RIGHT),cross,visit);
    return train.get_answer();
}