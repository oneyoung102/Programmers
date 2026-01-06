#include <vector>
#include <queue>
#include <cmath>


using namespace std;

bool can_arrive(vector<int>& gps_log, vector<vector<int>>& two_point_distance, int pos1, int pos2)
{
    return pos2-pos1 >= two_point_distance[gps_log[pos1]][gps_log[pos2]];
}

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> linked_point(n+1,vector<int>());
    for(vector<int> v : edge_list)
    {
        linked_point[v[0]].push_back(v[1]);
        linked_point[v[1]].push_back(v[0]);
    }
    for(int i = 1 ; i <= n ; ++i) // 자기 자신 연결
        linked_point[i].push_back(i);

    vector<vector<int>> two_point_distance(n+1,vector<int>(n+1,k+1));// 점과 점 간의 거리 구하기
    for(int i = 1 ; i <= n ; ++i)
    {
        two_point_distance[i][i] = 0;

        int distance = 1;
        queue<int> curr_points;
        curr_points.push(i);
        while(!curr_points.empty())
        {
            queue<int> curr_linked_points;
            while(!curr_points.empty())
            {
                for(int p : linked_point[curr_points.front()])
                    if(two_point_distance[i][p] == k+1)
                    {
                        curr_linked_points.push(p);
                        two_point_distance[i][p] = distance;
                    }
                curr_points.pop();
            }
            curr_points = std::move(curr_linked_points);
            ++distance;
        }
    }
    vector<int> max_same_dp(k,-1);
    max_same_dp[0] = 1;
    for(int i = 1 ; i < k ; ++i)
        for(int pos = 0 ; pos < i ; ++pos)//gps_log 범위 내에서 탐색
            if(can_arrive(gps_log,two_point_distance,pos,i) && max_same_dp[pos] != -1)//첫번째 비교점과 두번째 비교점이 연결된다면
                max_same_dp[i] = max(max_same_dp[pos]+1,max_same_dp[i]);     
    if(max_same_dp[k-1] == -1)
        return -1;
    return k-max_same_dp[k-1];
}