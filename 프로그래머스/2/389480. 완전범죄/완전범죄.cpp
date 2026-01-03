#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool criterion(vector<int> A, vector<int> B)
{
    return B[0]*A[1] < A[0]*B[1];
}
int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int thiefB = 0;
    vector<vector<int>> copy = info;
    sort(copy.begin(),copy.end(),criterion);
    for(vector<int> i : copy)
        for(int j : i)
        std::cout<<j<<",";
    for(int i = 0 ; i < copy.size() ; ++i)
    {     
        if(thiefB + copy[i][1] < m)
            thiefB += copy[i][1];
        else
        {
            if(answer + copy[i][0] < n)
                answer += copy[i][0];
            else
            {
                answer = -1;
                break;
            }
        }
    }
    return answer;
}