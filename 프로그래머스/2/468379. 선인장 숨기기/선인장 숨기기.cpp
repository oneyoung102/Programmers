#include <vector>
#include <set>

using namespace std;

using Pos = vector<int>;

vector<int> solution(int m, int n, int h, int w, vector<Pos> drops) {
    vector<vector<int>> optimal(m,vector<int>(n,drops.size()));
    for(int i = 0 ; i < drops.size() ; ++i)
        optimal[drops[i][0]][drops[i][1]] = i;

    for(int i = 0 ; i < n ; ++i)
    {
        int prev;
        set<int> accumulated;
        for(int j = 0 ; j < m-h+1 ; ++j)
        {
            if(j == 0)
                for(int k = 0 ; k < h-1 ; ++k)
                    accumulated.insert(optimal[k][i]);
            else
                accumulated.erase(prev);  

            accumulated.insert(optimal[j+h-1][i]);
            prev = optimal[j][i];
            optimal[j][i] = *accumulated.begin();
        }
    }
            
    Pos answer;
    for(int i = 0 ; i < m-h+1 ; ++i)
    {
        int prev;
        set<int> accumulated;
        for(int j = 0 ; j < n-w+1 ; ++j)
        {
            if(j == 0)
                for(int k = 0 ; k < w-1 ; ++k)
                    accumulated.insert(optimal[i][k]);
            else
                accumulated.erase(prev);

            accumulated.insert(optimal[i][j+w-1]);
            prev = optimal[i][j];
            optimal[i][j] = *accumulated.begin();
            if(answer.empty() || optimal[i][j] > optimal[answer[0]][answer[1]]) //영역 내 최소 중 최대 택함
                answer = {i,j};
        }
    }
    return answer;
}