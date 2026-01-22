#include <string>
#include <vector>
#include <utility>
#include <climits>
#include <cmath>

using namespace std;
using coord = pair<long long,long long>;
using line = vector<int>;

coord get_coord(line& l1, line& l2)
{
    const double bottom = static_cast<long long>(l1[0])*l2[1]-static_cast<long long>(l1[1])*l2[0];
    if(bottom == 0)
        return make_pair(LLONG_MAX,LLONG_MAX);
    const double x = (static_cast<long long>(l1[1])*l2[2]-static_cast<long long>(l1[2])*l2[1])/bottom;
    const double y = (static_cast<long long>(l1[2])*l2[0]-static_cast<long long>(l1[0])*l2[2])/bottom;
    if(x != floor(x) || y != floor(y))
        return make_pair(LLONG_MAX,LLONG_MAX);
    return make_pair(x,y);
}

vector<string> solution(vector<line> lines) {
    long long min_x = LLONG_MAX, max_x = LLONG_MIN, min_y = LLONG_MAX, max_y = LLONG_MIN;
    vector<coord> coords;
    for(int i = 0 ; i < lines.size()-1 ; ++i)
    {
        for(int j = i+1 ; j < lines.size() ; ++j)
        {
            coord c = get_coord(lines[i],lines[j]);
            if(c.first == LLONG_MAX || c.second == LLONG_MAX)
                continue;
            coords.push_back(c);
            if(min_x > c.first)
                min_x = c.first;
            if(max_x < c.first)
                max_x = c.first;
            if(min_y > c.second)
                min_y = c.second;
            if(max_y < c.second)
                max_y = c.second;
        }
    }
    const size_t row = max_y-min_y+1, col = max_x-min_x+1;
    vector<string> answer(row,string(col,'.'));
    for(coord& c : coords)
        answer[row-1-c.second+min_y][c.first-min_x] = '*';
    return answer;
}