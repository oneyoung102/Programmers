#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(),people.end());
    deque<int> pdq(people.begin(),people.end());
    int answer = 0;
    while(!pdq.empty())
    {
        if(pdq.size() != 1 && pdq.front()+pdq.back() <= limit)
            pdq.pop_front();
        pdq.pop_back();
        ++answer;
    }
    return answer;
}