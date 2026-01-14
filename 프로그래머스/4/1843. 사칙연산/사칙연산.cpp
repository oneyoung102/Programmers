#include <vector>
#include <string>
#include <climits>

using namespace std;

int solution(vector<string> arr)
{
    const int num_count = (arr.size()+1)/2;
    vector<vector<int>> dp_max(num_count,vector<int>(num_count,INT_MIN));//a~b번째 숫자까지 연산했을 때의 최댓값
    vector<vector<int>> dp_min(num_count,vector<int>(num_count,INT_MAX));//a~b번째 숫자까지 연산했을 때의 최솟값
    for(int i = 0 ; i < num_count ; ++i)
    {
        dp_max[i][i] = stoi(arr[i*2]);
        dp_min[i][i] = stoi(arr[i*2]);
    }
    for(int n = 1 ; n <= num_count ; ++n)
        for(int i = 0 ; i+n-1 < num_count ; ++i)
        {
            const int end = i+n-1;
            for(int j = i ; j < end ; ++j)
            {
                const string oper = arr[j*2+1];
                if(oper == "+")
                {
                    dp_max[i][end] = max(dp_max[i][end],dp_max[i][j]+dp_max[j+1][end]);
                    dp_min[i][end] = min(dp_min[i][end],dp_min[i][j]+dp_min[j+1][end]);
                }
                else
                {
                    dp_max[i][end] = max(dp_max[i][end],dp_max[i][j]-dp_min[j+1][end]);
                    dp_min[i][end] = min(dp_min[i][end],dp_min[i][j]-dp_max[j+1][end]);
                }
            }
        }   
    return dp_max[0][num_count-1];
}