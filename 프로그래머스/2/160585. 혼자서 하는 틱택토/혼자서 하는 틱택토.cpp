#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> board) {
    int amount = 0;
    for(auto& i : board)
        for(auto& j : i)
            if(j == 'O')
                amount++;
            else if(j == 'X')
                amount--;
    if(amount < 0 || amount > 1)
        return 0;
    map<char, int> bingo;
    for(int i = 0 ; i < 3 ; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '.')
            bingo[board[i][0]]++;
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '.')
            bingo[board[0][i]]++;
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '.')
        bingo[board[0][0]]++;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '.')
        bingo[board[2][0]]++;
    if(bingo['O'] > 0 && bingo['X'] > 0)
        return 0;
    
    if((bingo['O'] > 0 && amount <= 0) ||(bingo['X'] > 0 &&  amount >= 1))
        return 0;
    return 1;
}