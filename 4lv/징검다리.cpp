//2025-12-01 15:09:33
//https://school.programmers.co.kr/learn/courses/30/lessons/43236

#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end());
    int left = 1, right = distance;
    while(left <= right)
    {
        const int mid = (left+right)/2;
        bool exist = false; // mid와 같은 거리의 바위가 존재하는가
        int remove = 0/*제거한 바위 수*/, dist = 0/*/바위 간의 거리 누적*/, prev = 0;//전 바위
        for(const int rock : rocks)
        {
            dist += rock-prev;
            if(dist >= mid)
            {
                if(dist == mid)
                    exist = true;
                dist = 0;
            }
            else
                ++remove;
            prev = rock;
        }
        if(remove > n)
            right = mid-1;
        else
        {
            if(exist)
                answer = max(answer,mid);
            left = mid+1;
        }
    }
    return answer;
}
