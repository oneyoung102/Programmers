#include <string>
#include <vector>
#include <climits>

using namespace std;

class cart {
public:
    vector<int> coord;
    int goal;
    vector<vector<bool>> visited;

    cart(vector<int>& start, int row, int col, int g) : goal(g) {
        coord = start;
        visited = vector<vector<bool>>(row, vector<bool>(col, false));
        visited[start[0]][start[1]] = true;
    }
};

const vector<vector<int>> dir = {
    {1,0}, {-1,0}, {0,1}, {0,-1}
};

int answer = INT_MAX;

void find_route(vector<vector<int>>& maze, cart& red, cart& blue, int turn)
{
    const int r_r = red.coord[0], r_c = red.coord[1];
    const int b_r = blue.coord[0], b_c = blue.coord[1];
    if (maze[r_r][r_c] == red.goal && maze[b_r][b_c] == blue.goal)
    {
        answer = min(answer,turn);
        return;
    }
    if (maze[r_r][r_c] == red.goal)
    {
        for (const auto& d_b : dir)
        {
            int nb_r = b_r + d_b[0], nb_c = b_c + d_b[1];
            if (0 > nb_r || nb_r >= maze.size() || 0 > nb_c || nb_c >= maze[0].size() || maze[nb_r][nb_c] == 5 || blue.visited[nb_r][nb_c] || r_r == nb_r && r_c == nb_c)
                continue;
            blue.visited[nb_r][nb_c] = true;
            blue.coord = {nb_r, nb_c};
            find_route(maze, red, blue,turn+1);
            blue.visited[nb_r][nb_c] = false;
        }
        blue.coord = {b_r, b_c};
    }
    else if (maze[b_r][b_c] == blue.goal)
    {
        for (const auto& d_r : dir)
        {
            int nr_r = r_r + d_r[0], nr_c = r_c + d_r[1];
            if (0 > nr_r || nr_r >= maze.size() || 0 > nr_c || nr_c >= maze[0].size() || maze[nr_r][nr_c] == 5 || red.visited[nr_r][nr_c] || nr_r == b_r && nr_c == b_c)
                continue;
            red.visited[nr_r][nr_c] = true;
            red.coord = {nr_r, nr_c};
            find_route(maze, red, blue,turn+1);
            red.visited[nr_r][nr_c] = false;
        }
        red.coord = {r_r, r_c};
    }
    else
    {
        for (const auto& d_r : dir)
        {
            int nr_r = r_r + d_r[0], nr_c = r_c + d_r[1];
            if (0 > nr_r || nr_r >= maze.size() || 0 > nr_c || nr_c >= maze[0].size() || maze[nr_r][nr_c] == 5 || red.visited[nr_r][nr_c] || nr_r == b_r && nr_c == b_c)
                continue;
            red.visited[nr_r][nr_c] = true;
            red.coord = {nr_r, nr_c};
            for (const auto& d_b : dir)
            {
                int nb_r = b_r + d_b[0], nb_c = b_c + d_b[1];
                if (0 > nb_r || nb_r >= maze.size() || 0 > nb_c || nb_c >= maze[0].size() || maze[nb_r][nb_c] == 5 || blue.visited[nb_r][nb_c] || nr_r == nb_r && nr_c == nb_c)
                    continue;
                blue.visited[nb_r][nb_c] = true;
                blue.coord = {nb_r, nb_c};
                find_route(maze, red, blue,turn+1);
                blue.visited[nb_r][nb_c] = false;
            }
            red.visited[nr_r][nr_c] = false;
            blue.coord = {b_r, b_c};
        }
        red.coord = {r_r, r_c};
        for (const auto& d_b : dir)
        {
            int nb_r = b_r + d_b[0], nb_c = b_c + d_b[1];
            if (0 > nb_r || nb_r >= maze.size() || 0 > nb_c || nb_c >= maze[0].size() || maze[nb_r][nb_c] == 5 || blue.visited[nb_r][nb_c] || r_r == nb_r && r_c == nb_c)
                continue;
            blue.visited[nb_r][nb_c] = true;
            blue.coord = {nb_r, nb_c};
            for (const auto& d_r : dir)
            {
                int nr_r = r_r + d_r[0], nr_c = r_c + d_r[1];
                if (0 > nr_r || nr_r >= maze.size() || 0 > nr_c || nr_c >= maze[0].size() || maze[nr_r][nr_c] == 5 || red.visited[nr_r][nr_c] || nr_r == nb_r && nr_c == nb_c)
                    continue;
                red.visited[nr_r][nr_c] = true;
                red.coord = {nr_r, nr_c};
                find_route(maze, red, blue,turn+1);
                red.visited[nr_r][nr_c] = false;
            }
            blue.visited[nb_r][nb_c] = false;
            red.coord = {r_r, r_c};
        }
        blue.coord = {b_r, b_c};
    }
}

int solution(vector<vector<int>> maze)
{
    vector<int> red_start(2, -1), blue_start(2, -1);

    for (int i = 0; i < maze.size(); ++i)
        for (int j = 0; j < maze[0].size(); ++j)
            if (maze[i][j] == 1)
                red_start = {i, j};
            else if (maze[i][j] == 2)
                blue_start = {i, j};

    cart red(red_start, maze.size(), maze[0].size(), 3);
    cart blue(blue_start, maze.size(), maze[0].size(), 4);
    find_route(maze, red, blue,0);
    if(answer == INT_MAX)
        return 0;
    return answer;
}