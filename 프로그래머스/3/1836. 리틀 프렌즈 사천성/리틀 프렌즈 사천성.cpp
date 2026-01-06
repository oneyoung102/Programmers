#include <string>
#include <vector>
#include <map>
#include <set>
#include <array>

using namespace std;

string solution(int m, int n, vector<string> board) {
    string answer = "";
    map<char,set<char>> BlockingWhat;
    map<char,array<set<char>,2>> BlockingBy;
    set<char> linkings;

    map<char, vector<pair<int,int>>> pos;
    for(int i = 0 ; i < board.size() ; ++i)
        for(int j = 0 ; j < board[0].size() ; ++j)
        {
            const char linking = board[i][j];
            if(linking != '*' && linking != '.')
            {
                linkings.insert(linking);

                auto& it = pos[linking];
                it.push_back(make_pair(i,j));
                if(it.size() == 2)
                {
                    int x_f = it[0].first, x_s = it[1].first, y_f = it[0].second, y_s = it[1].second;
                    if(x_f > x_s)
                        swap(x_f,x_s);
                    if(y_f > y_s)
                        swap(y_f,y_s);
                    bool impossible[2] = {false,false};
                    for(int n = 0 ; n < 2 ; ++n)
                    {
                        for(int k = x_f ; k <= x_s ; ++k)
                        {
                            const char block = board[k][it[n].second];
                            if(block != '.' && block != linking)
                            {
                                BlockingBy[linking][n].insert(block);
                                if(block == '*')
                                    impossible[n] = true;
                                else
                                    BlockingWhat[block].insert(linking);
                            }
                        }
                        for(int k = y_f ; k <= y_s; ++k)
                        {
                            const char block = board[it[1-n].first][k];
                            if(block != '.' && block != linking)
                            {
                                BlockingBy[linking][n].insert(block);
                                if(block == '*')
                                    impossible[n] = true;
                                else
                                    BlockingWhat[block].insert(linking);
                            }
                        }
                    }
                    if(impossible[0] && impossible[1])
                        return "IMPOSSIBLE";
                }
            }
        }
    while(!linkings.empty())
    {
        auto it = linkings.begin();
        while(true)
        {
            if(BlockingBy[*it][0].empty() || BlockingBy[*it][1].empty())
            {
                const char linking = *it;
                answer += linking;
                for(auto it_ = BlockingWhat[linking].begin() ; it_ != BlockingWhat[linking].end() ; ++it_)
                    for(int n = 0 ; n < 2 ; ++n)
                        BlockingBy[*it_][n].erase(linking);
                linkings.erase(it);
                break;
            }
            if(++it == linkings.end())
                return "IMPOSSIBLE";
        }
    }
    return answer;
}