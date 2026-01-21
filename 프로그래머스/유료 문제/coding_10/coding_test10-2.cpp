#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    const bool BoardIsEven = board.size()%2 == 0 && board[0].size()%2 == 0;
    if(BoardIsEven)
    {
        int excepted = 1000;
        for(int i = 0 ; i < board.size() ; ++i)
            for(int j = 0 ; j < board[0].size() ; ++j)
            {
                answer += board[i][j];
                if((i+j)%2 == 1)
                    if(board[i][j] < excepted)
                        excepted = board[i][j];
            }
        answer -= excepted;
    }
    else
        for(int i = 0 ; i < board.size() ; ++i)
            for(int j = 0 ; j < board[0].size() ; ++j)
                answer += board[i][j];
    return answer;
}

int main()
{
    printf("%d",solution({{1,2,3},{4,5,6},{7,8,9}}));
    //{{1,2},{3,4}}
    //
    return 0;
}
