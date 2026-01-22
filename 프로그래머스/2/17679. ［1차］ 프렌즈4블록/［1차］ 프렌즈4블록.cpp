#include <string>
#include <vector>
#include <utility>
#include <set>

using namespace std;
using coord = pair<int,int>;

enum{
    blank = '0'
};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<int> maxHeight(n,m);
    while(true)
    {
        bool blockExist = false;
        set<coord> removes;
        for(int i = 0 ; i < n-1 ; ++i)
            for(int j = m-maxHeight[i] ; j < m-1 ; ++j)
            {
                const char compare = board[j][i];
                if(compare == blank)
                    continue;
                if(compare == board[j][i+1] && compare == board[j+1][i+1] && compare == board[j+1][i])
                {
                    removes.insert(make_pair(j,i));
                    removes.insert(make_pair(j,i+1));
                    removes.insert(make_pair(j+1,i+1));
                    removes.insert(make_pair(j+1,i));
                    blockExist = true;
                }
            }
        if(!blockExist)
            break;

        answer += removes.size();
        for(const auto& r : removes)
            board[r.first][r.second] = blank;

        for(int i = 0 ; i < n ; ++i)
        {
            int firstBlankPos = -1;
            for(int j = m-1 ; j >= m-maxHeight[i] ; --j)
            {
                if(firstBlankPos == -1)
                {
                    if(board[j][i] == blank)
                        firstBlankPos = j;
                }
                else
                {
                    if(board[j][i] == blank)
                        continue;
                    board[firstBlankPos--][i] = board[j][i];
                    board[j][i] = blank;
                }
            }
            if(firstBlankPos != -1)
                maxHeight[i] = m-firstBlankPos;
        }
    }
    return answer;
}