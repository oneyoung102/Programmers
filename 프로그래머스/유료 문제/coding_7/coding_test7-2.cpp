#include <string>
#include <vector>
 
using namespace std;

vector<vector<int>> solution(int rows, int columns) {
    vector<vector<int>> answer(rows,vector<int>(columns,0));
    int zero = rows*columns-1;
    int r = 0, c = 0, num = 1;
    answer[r][c] = num;
    while(zero > 0)
    {
        if(num%2 == 0)
        {
            if(r == rows-1)
                r = 0;
            else
                ++r;
        }  
        else
        {
            if(c == columns-1)
                c = 0;
            else
                ++c;
        }    
        if(answer[r][c] == 0)
            --zero;
        if(num%2 == 0 && r == 0 && c == 0)
            break;
        answer[r][c] = ++num;
    }
    return answer;

}

int main()
{
    vector<vector<int>> vec = solution(3,4);
    for(vector<int>& i : vec)
    {
        for(int& j : i)
            printf("%d ",j);
        printf("\n");
    }
}
 