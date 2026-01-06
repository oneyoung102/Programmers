#include <vector>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = -1;
    int left_cycle = 0, right_cycle = 1e8;
    while(left_cycle <= right_cycle)
    {
        const int mid_cycle = (left_cycle+right_cycle)/2;
        vector<int> rests;
        long long time = 0;
        for(int i = 0 ; i < food_times.size() ; ++i)
            if(food_times[i] > mid_cycle)
            {
                time += mid_cycle;
                rests.push_back(i);
            }
            else
                time += food_times[i];
        if(time > k)
            right_cycle = mid_cycle-1;
        else
        {
            left_cycle = mid_cycle+1;   
            if(k-time < rests.size())
                answer = rests[k-time]+1; 
        }
    }
    return answer;
}