#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> snail;
    for(size_t i = 1 ; i <= n ; ++i)
        snail.push_back(vector<int>(i,0));
        
    int r = 0, c = 0, mode = 0;
    const int count = n*(n+1)/2;
    for(int i = 0 ; i < count ; ++i)
    {
        snail[r][c] = i+1;
        if(mode%3 == 0)
        {
            if(r+1 != n && snail[r+1][c] == 0)
                ++r;
            else
            {
                ++mode;
                ++c;
            }
        }
        else if(mode%3 == 1)
        {
            if(c+1 != snail[r].size() && snail[r][c+1] == 0)
                ++c;
            else
            {
                ++mode;
                --r;
                --c;
            }
        }
        else if(mode%3 == 2)
        {
            if(snail[r-1][c-1] == 0)
            {
                --r;
                --c;
            }
            else
            {
                ++mode;
                ++r;
            }
        }
    }
    vector<int> answer;
    for(const auto& v : snail)
        for(const int n : v)
            answer.push_back(n);
    return answer;
}