#include <string>
#include <vector>
#include <map>

using namespace std;
long long count_min(vector<vector<int>>& positions, int axis)
{
    long long answer = 1;
    struct side{
        int left, right;
    };

    map<int,int> amount_about_axis;
    for(vector<int>& it : positions)
        ++amount_about_axis[it[axis-'x']];

    const auto begin_aba = amount_about_axis.begin();

    int minimum_l = 1;
    for(auto it = begin_aba ; it != amount_about_axis.end() ; ++it)
        minimum_l += ((it->first)-(begin_aba->first))*(it->second);
    side Am = {0,(int)positions.size()}, L = {0,minimum_l-1};
    for(auto it = begin_aba ; it != amount_about_axis.end() ; ++it)
    {
        Am.left += it->second;
        Am.right -= it->second;
        if(L.left+L.right < minimum_l)
        {
            minimum_l = L.left+L.right;
            if(Am.left == Am.right)
            {
                auto next = ++it;
                --it;
                answer = next->first-it->first+1;
            }
        }
        L.left += Am.left;
        L.right -= Am.right;
    }
    return answer;
}
long long solution(vector<vector<int>> positions) {
    return count_min(positions,'x')*count_min(positions,'y');
}

int main()
{
vector<vector<int>> positions = []{
    vector<vector<int>> v;
    int x = -1000000, y = -1000000;
    for (int i = 0; i < 300000; ++i) {
        v.push_back({x, y});
        x += 7;
        y += 11;
        // 값이 범위 넘으면 wrap-around
        if (x > 100000) x = -1000000 + (x - 100000 - 1);
        if (y > 100000) y = -1000000 + (y - 100000 - 1);
    }
    return v;
}();
    printf("   %lld",solution(positions));
    //{100070, -100103},{100097, 902303},{-990130, -902329},{-301211, -331233}
    // {-6, 0}, {0, 0}, {1, 0}, {1, 1}
    //{1, 1}, {-1, 1}, {0, 0}, {-1, -1}
    return 0;
}