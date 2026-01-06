#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> dist_memo(10,vector<int>(10,INT_MAX));

int get_dist(int start, int dest)
{
    if(dist_memo[start][dest] != INT_MAX)
        return dist_memo[start][dest];
    if(start == dest)
        return dist_memo[start][dest] = 1;
    const int sub_start = (start == 0) ? 10 : (start-1);
    const int sub_dest = (dest == 0) ? 10 : (dest-1);
    const int row_dist = abs(sub_start/3-sub_dest/3);
    const int col_dist = abs(sub_start%3-sub_dest%3);
    const int dist = min(row_dist,col_dist)*3 + abs(row_dist-col_dist)*2;
    dist_memo[start][dest] = dist;
    dist_memo[dest][start] = dist;
    return dist;
}
int solution(string numbers) {
    vector<vector<vector<int>>> dp(numbers.size()+1,vector<vector<int>>(10,vector<int>(10,INT_MAX)));
    dp[0][4][6] = 0;
    for(int i = 0 ; i < dp.size()-1 ; ++i)
        for(int j = 0 ; j < 10 ; ++j)
            for(int k = 0 ; k < 10 ; ++k)
            {
                if(dp[i][j][k] == INT_MAX)
                    continue;
                const int dest = numbers[i]-'0';
                if(dest != k)
                    dp[i+1][dest][k] = min(dp[i+1][dest][k],dp[i][j][k]+get_dist(j,dest)); 
                if(dest != j)
                    dp[i+1][dest][j] = min(dp[i+1][dest][j],dp[i][j][k]+get_dist(k,dest));
            }
    int answer = INT_MAX;
    for(int i = 0 ; i < 10 ; ++i)
        for(int j = 0 ; j < 10 ; ++j)
            answer = min(answer,dp.back()[i][j]);
    return answer;
}