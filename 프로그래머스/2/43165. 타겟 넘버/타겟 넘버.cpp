#include <vector>

using namespace std;

int answer = 0;
vector<int> n;
int t;
void calc(int p, int num)
{
    if(p == n.size())
    {
        if(num == t)
            ++answer;
        return;
    }
    calc(p+1,num+n[p]);
    calc(p+1,num-n[p]);
}

int solution(vector<int> numbers, int target) {
    n = numbers;
    t = target;
    calc(0,0);
    return answer;
}