#include <string>
#include <vector>

using namespace std;

vector<int> answer(2,0);
vector<vector<int>> arr;
void zip(int r, int c, int level)
{
    const int compare = arr[r][c];
    if(level == 1)
    {
        ++answer[compare];
        return;
    }
    bool zip_possible = true;
    for(int i = 0 ; i < level ; ++i)
        for(int j = 0 ; j < level ; ++j)
            if(compare != arr[r+i][c+j])
            {
                const int next_level = level/2;
                zip(r,c,next_level);
                zip(r+next_level,c,next_level);
                zip(r,c+next_level,next_level);
                zip(r+next_level,c+next_level,next_level);
                return;
            }
    ++answer[compare];
}

vector<int> solution(vector<vector<int>> array) {
    arr = array;
    zip(0,0,array.size());
    return answer;
}