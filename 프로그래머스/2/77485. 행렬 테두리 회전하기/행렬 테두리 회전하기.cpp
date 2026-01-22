#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int rotate_and_mini(int x1, int y1, int x2, int y2, vector<vector<int>>& numbers)
{
    int before = numbers[x1][y1];
    int mini = before;
    for(int i = y1+1 ; i <= y2 ; ++i)
    {
        swap(numbers[x1][i],before);
        mini = min(mini,before);
    }
    for(int i = x1+1 ; i <= x2 ; ++i)
    {
        swap(numbers[i][y2],before);
        mini = min(mini,before);
    }
    for(int i = y2-1 ; i >= y1 ; --i)
    {
        swap(numbers[x2][i],before);
        mini = min(mini,before);
    }
    for(int i = x2-1 ; i >= x1 ; --i)
    {
        swap(numbers[i][y1],before);
        mini = min(mini,before);
    }
    return mini;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> numbers(rows,vector<int>(columns));
    int n = 0;
    for(int i = 0 ; i < rows ; ++i)
        for(int j = 0 ; j < columns ; ++j)
            numbers[i][j] = ++n;
    for(int i = 0 ; i < queries.size() ; ++i)
        answer.push_back(rotate_and_mini(queries[i][0]-1,queries[i][1]-1,queries[i][2]-1,queries[i][3]-1,numbers));
    return answer;
}