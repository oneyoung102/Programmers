#include <vector>
#include <queue>
#include <utility>

using namespace std;
using P = pair<int,int>;

struct compare
{
    bool operator()(P& a, P&b)
    {
        if(a.first < b.first)
            return true;
        if(a.first == b.first)
            return a.second > b.second;
        return false;
    }
};

int solution(vector<int> stones, int k) {
    int answer = 2e9;
    int left = 0, right = 0;
    int max_stone_stack = 0;
    priority_queue<P,vector<P>,compare> pq;
    while(true)
    {
        if(right - left < k)
        {   
            pq.push(make_pair(stones[right],right));
            max_stone_stack = max(max_stone_stack,stones[right]);
            ++right;
        }
        else
        {
            answer = min(answer,max_stone_stack);
            if(answer == 1) break;
            if(right >= stones.size()) break;
            if(stones[left] == max_stone_stack)
            {
                max_stone_stack = 0;
                while(!pq.empty())
                {
                    const P temp = pq.top();  
                    pq.pop();
                    if(temp.second > left)
                    {
                        max_stone_stack = temp.first;
                        break;
                    }
                }
            }
            ++left;
        }
    }
    return answer;
}