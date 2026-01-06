#include <string>
#include <vector>

using namespace std;
using board = vector<vector<int>>;

bool solution(board key, board lock) {
    int holes = 0;
    for(const auto& v : lock)
        for(const int e : v)
            if(e == 0)
                ++holes;
    const int N = key.size(), M = lock.size();
    vector<board> keys;
    keys.push_back(key);
    board turned(N,vector<int>(N,0));
    for(int t = 0 ; t < 3 ; ++t)
    {
        for(int i = 0 ; i < N ; ++i)
            for(int j = 0 ; j < N ; ++j)
                turned[j][N-1-i] = key[i][j];
        keys.push_back(turned);
        key = turned;
    }
    for(int i = 1-N ; i < M ; ++i)
        for(int j = 1-N ; j < M ; ++j)
        {
            const int r1 = max(i,0), c1 = max(j,0);
            const int r2 = min(i+N,M), c2 = min(j+N,M);
            if((r2-r1)*(c2-c1) < holes)
                continue;
            for(const board& k : keys)
            {
                bool same = true;
                int holes_count = 0;
                for(int r = r1 ; r < r2 && same ; ++r)
                    for(int c = c1 ; c < c2 && same ; ++c)
                        if(lock[r][c] != k[r-i][c-j])
                            holes_count += k[r-i][c-j];
                        else
                            same = false;
                if(same && holes_count == holes)
                    return true;
            }
        }
    return false;
}