#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> amount(n,1);
    for(int i = 0 ; i < n ; i++)
    {
        if(find(lost.begin(), lost.end(),i+1) != lost.end())
            amount[i]-=1;
        if(find(reserve.begin(), reserve.end(),i+1) != reserve.end())
            amount[i]+=1;
    }
    if(find(amount.begin(),amount.end(),0) != amount.end() || find(amount.begin(),amount.end(),2) != amount.end())
    {
       for(int i = 0 ; i < n ; i++)
        {
            if(amount[i] == 2)
            {
                if(amount[i-1] == 0 & i > 0)
                    amount[i-1]++;
                else if(amount[i+1] == 0 && i < n-1)
                    amount[i+1]++;
                amount[i]--;
            }
        } 
    }   
    for(auto& it  : amount)
        if(it == 1)
           answer++;
    return answer;
}