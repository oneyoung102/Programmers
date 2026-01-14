#include <queue>
#include <vector>

using namespace std;

inline int get_day(int p, int s)
{
    return (100-p+s-1)/s;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int big_guy = get_day(progresses[0],speeds[0]), accumulate = 1;
    for(int i = 1 ; i < progresses.size() ; ++i)
    {
        const int temp = get_day(progresses[i],speeds[i]);
        if(temp > big_guy)
        {
            answer.push_back(accumulate);
            accumulate = 1;
            big_guy = temp;
        }
        else
            ++accumulate;
    }
    answer.push_back(accumulate);
    return answer;
}