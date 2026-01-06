#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

constexpr int adjusted_left(int i, int dum)
{
    if(i < 0) return i+dum;
    return i;
}
constexpr int adjusted_right(int i, int right)
{
    if(i >= right) return i-right;
    return i;
}

int answer = INT_MAX;

int get_min_peeple(int n, vector<int>& weak, vector<int>& dist, int dist_p)
{
    if(dist_p == dist.size())
        return INT_MAX;
    if(dist[dist_p] >= weak.back()-weak.front())
        return dist_p+1;

    vector<vector<int>> possible_weak_pos;
    int right_index_start = 0;
    const int weak_spots = weak.size();
    for(int i = 0 ; i < weak_spots ; ++i)
        for(int j = i+weak_spots-1 ; j >= right_index_start  ; --j)
        {                    
            const int right_index = adjusted_right(j,weak_spots);
            const int weaks_dist = adjusted_left(weak[right_index]-weak[i],n);
            if(weaks_dist > dist[dist_p])
                continue;
            possible_weak_pos.push_back({i,right_index});
            right_index_start = j+1;
            break;
        }
    for(vector<int>& v : possible_weak_pos)
    {
        vector<int> temp_weak;
        if(v[0] <= v[1])
        {
            temp_weak.insert(temp_weak.end(),weak.begin(),weak.begin()+v[0]);
            temp_weak.insert(temp_weak.end(),weak.begin()+v[1]+1,weak.end());
        }
        else
            temp_weak.insert(temp_weak.end(),weak.begin()+v[1]+1,weak.begin()+v[0]);
        if(temp_weak.empty())
            return dist_p+1;
        const int temp_min_people = get_min_peeple(n,temp_weak,dist,dist_p+1);
        if(temp_min_people == INT_MAX)
            continue;
        answer = min(temp_min_people,answer);
    }
    return answer;
}
int solution(int n, vector<int> weak, vector<int> dist) {
    sort(dist.begin(),dist.end(),greater<int>());
    const int min_people = get_min_peeple(n,weak,dist,0);
    if(min_people == INT_MAX)
        return -1;
    return min_people;
}