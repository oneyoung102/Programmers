#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    vector<vector<int>> number_idx(500001,vector<int>());
    for(int i = 0 ; i < a.size() ; ++i)
        number_idx[a[i]].push_back(i);
    int answer = 0;
    for(const auto& nidx : number_idx)
    {
        if(nidx.empty())
            continue;
        const int num = a[nidx[0]], s = a.size();
        int length = 0;
        vector<bool> checked(a.size(),false);
        for(const int idx : nidx)
        {   
            int with_idx = -1;
            if(idx == 0)
            {
                if(idx+1 < s && num != a[idx+1])
                with_idx = idx+1;
            }
            else if(idx == s-1)
            {
                if(idx > 0 && num != a[idx-1] && !checked[idx-1])
                    with_idx = idx-1;
            }
            else
            {
                if(num != a[idx-1] && !checked[idx-1])
                    with_idx = idx-1;
                else if(num != a[idx+1])
                    with_idx = idx+1;
            }
            if(with_idx != -1)
            {
                length += 2;
                checked[idx] = true;
                checked[with_idx] = true;
            }
        }
        answer = max(answer,length);
    }
    return answer;
}