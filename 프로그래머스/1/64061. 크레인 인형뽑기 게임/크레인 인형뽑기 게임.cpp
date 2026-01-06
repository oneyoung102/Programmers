#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;
    for(int j=0 ; j<moves.size() ; j++)
        for(int i=0 ; i<board[0].size() ; i++)
            if(board[i][moves[j]-1]!=0)
            {
                if(basket.back()==board[i][moves[j]-1]&&!basket.empty())
                {
                    basket.pop_back();
                    answer+=2;
                }   
                else         
                    basket.push_back(board[i][moves[j]-1]);    
                board[i][moves[j]-1] = 0;
                break;
            }
    return answer;
}