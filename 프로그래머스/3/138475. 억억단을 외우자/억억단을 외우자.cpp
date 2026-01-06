#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int e, vector<int> S) {
    vector<vector<int>> starts;
    for(int i = 0 ; i < S.size() ; ++i)
        starts.push_back({S[i],i});
    sort(starts.begin(),starts.end());

    vector<int> answer(S.size(),0);
    int max_appear = 0, max_num = 0;
    while(!starts.empty())
    {
        const int num = starts.back()[0], idx = starts.back()[1];
        starts.pop_back();
        while(e >= num)
        {     
            int appear = 0, sub_e = e, half = 0;
            while(sub_e%2 == 0)
            {
                sub_e /= 2;
                ++half;
            } 
            const double root = sqrt(sub_e);
            appear += (int)(root == (int)root);
            for(int n = 1 ; n < root ; n += 2)
                appear += 2*(int)(sub_e%n == 0);
            appear *= half+1;
            if(appear >= max_appear)
            {
                max_appear = appear;
                max_num = e;
            }
            --e;
        }
        answer[idx] = max_num;
    }
    return answer;
}