#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(long long begin, long long end) {
    const int n = end-begin+1;
    int checked_n = 0;
    vector<int> answer(n,0);
    const int block_begin = 1, block_end = min((int)1e7,(int)(end/2));
    for(int i = block_end ; i >= block_begin ; --i)
    {
        if(checked_n == n)
            break;
        const int init = (i*2 >= begin) ? i*2 : ceil((double)begin/i)*i;
        for(int k = init ; k <= end ; k += i)
            if(answer[k-begin] == 0)
            {
                answer[k-begin] = i;
                ++checked_n;
            }
    }
    return answer;
}