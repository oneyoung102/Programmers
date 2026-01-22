#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> max_enems;
    for(const int e : enemy)
    {
        if(k > 0)
        {
            --k;
            max_enems.push(e);
        }
        else
        {
            const int max_enem_mini = max_enems.top();
            if(max_enem_mini < e)
            {
                if(n - max_enem_mini >= 0)
                    n -= max_enem_mini;
                else
                    break;
                max_enems.pop();
                max_enems.push(e);
            }
            else if(n - e >= 0)
                n -= e;          
            else
                break;
        }
        ++answer;
    }
    return answer;
}