#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    for(int i = -1 ; i <=1 ; i+=2)
        if(h+i>=0&&h+i<board.size())
            if(board[h][w]==board[h+i][w])
                answer++;  
    for(int i = -1 ; i <=1 ; i+=2)
        if(w+i>=0&&w+i<board.size())
            if(board[h][w]==board[h][w+i])
                answer++;  
    return answer;
}