//2025-11-17 12:21:13
//https://school.programmers.co.kr/learn/courses/30/lessons/49995

#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    const int N = cookie.size();
    vector<vector<int>> part_sums(N,vector<int>(N,0));
    part_sums[0][0] = cookie[0];
    for(int i = 1 ; i < N ; ++i)
        part_sums[0][i] = part_sums[0][i-1]+cookie[i];
    for(int i = 1 ; i < N ; ++i)
        for(int j = i ; j < N ; ++j)
            part_sums[i][j] = part_sums[i-1][j]-cookie[i-1];
            
    int answer = 0;
    for(int m = 0 ; m < N-1 ; ++m)
    {
        int l = m, r = m+1;
        while(0 <= l && r < N)
        {
            const int left_sum = part_sums[l][m], right_sum = part_sums[m+1][r];
            if(left_sum > right_sum)
                ++r;                   
            else if(left_sum < right_sum)
                --l;
            else
            {
                answer = max(answer,left_sum);
                ++r;
            }
        }
    }
    return answer;
}
