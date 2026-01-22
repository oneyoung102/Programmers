#include <utility>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> sc(scoville.begin(),scoville.end());
    int answer = 0;
    while(sc.top() < K)
    {
        if(sc.size() == 1)
            return -1;
        int food1 = sc.top(); sc.pop();
        int food2 = sc.top(); sc.pop();
        if(food1 > food2) swap(food1,food2);
        sc.push(food1+food2*2);
        ++answer;

    }
    return answer;
}