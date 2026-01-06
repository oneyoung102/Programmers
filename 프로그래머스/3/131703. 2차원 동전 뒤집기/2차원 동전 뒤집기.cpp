#include <vector>
#include <cmath>

using namespace std;

int answer = 0;
void invert_col(vector<vector<int>>& board, int col)
{
    ++answer;
    for(auto& b : board)
        b[col] = abs(b[col]-1);
    return;
}
void invert_row(vector<vector<int>>& board, int row)
{
    ++answer;
    for(auto& b : board[row])
        b = abs(b-1);
    return;
}

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    const int M = beginning.size(), N = beginning[0].size();

    int differ = 0;
    for(int c = 0 ; c < N ; ++c)
        if(beginning[0][c] != target[0][c])
            ++differ;
    if(differ > 1+N-differ)
        invert_row(beginning,0);

    for(int c = 0 ; c < N ; ++c)
        if(beginning[0][c] != target[0][c])
            invert_col(beginning,c);
    for(int r = 1 ; r < M ; ++r)
        if(beginning[r][0] != target[r][0])
            invert_row(beginning,r);

    for(int i = 0 ; i < M ; ++i)
        for(int j = 0 ; j < N ; ++j)
            if(beginning[i][j] != target[i][j])
                return -1;
    return answer;
}