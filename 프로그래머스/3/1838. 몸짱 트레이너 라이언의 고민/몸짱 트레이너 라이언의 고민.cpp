#include <vector>
#include <cmath>

using namespace std;
using point = pair<int,int>;

int get_distance(point p1, point p2)
{
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int get_maximum_clique_point(int sd, int n)
{
    int max_points = 0;
    for(int i = 0 ; i < n ; ++i)
    {
        vector<point> accumulated_points;
        accumulated_points.push_back(make_pair(i,0));
        for(int j = 0 ; j < n ; ++j)
        {
            for(int k = 0 ; k < n ; ++k)
            {
                bool pass_sign = false;
                const point candidate_point = make_pair(j,k);
                for(point p : accumulated_points)
                {
                    if(get_distance(p,candidate_point) < sd)
                    {
                        pass_sign = true;
                        break;
                    }
                }
                if(!pass_sign)
                    accumulated_points.push_back(candidate_point);
            }
        }
        max_points = max(max_points,(int)accumulated_points.size());
    }
    return max_points;
}

int solution(int n, int m, vector<vector<int>> timetable) {
    int max_people = 1;
    const int start_minute = 600;
    vector<int> people_at_time(721,0); // 600 ~ 1320
    for(int i = 0 ; i < people_at_time.size() ; ++i)
    {
        for(vector<int>& time : timetable)
            if(i+start_minute >= time[0] && i+start_minute <= time[1])
                people_at_time[i] += 1;
        if(people_at_time[i] > max_people)
            max_people = people_at_time[i];
    }
    if(max_people == 1)
        return 0;
    if(max_people > ceil(n*n/2.0))
        return 1;
    int shortest_distance = 2*n-2;//할당된 점이 2개일 떄, 최대 거리
    while(shortest_distance != 0)
    {
        const int people = get_maximum_clique_point(shortest_distance,n);
        if(people >= max_people)
            return shortest_distance;
        --shortest_distance;
    }
    return 0;
}