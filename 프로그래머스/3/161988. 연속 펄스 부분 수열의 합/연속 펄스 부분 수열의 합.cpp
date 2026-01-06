#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    int sign = 1;
    for(auto& it : sequence)
    {
        it *= sign;
        sign *= -1;
    }
    
    int i = 0;
    while(i < sequence.size())
    {
        long long sum = 0;
        int j = i;
        for(; j < sequence.size() ; ++j)
        {
            sum += sequence[j];
            if(sum < 0)
            {
                i = j+1;
                break;
            }
            answer = max(answer,sum);
        }
        if(j == sequence.size())
            break;
    }
    
    i = 0;
    while(i < sequence.size())
    {
        long long sum = 0;
        int j = i;
        for(; j < sequence.size() ; ++j)
        {
            sum += sequence[j];
            if(sum > 0)
            {
                i = j+1;
                break;
            }
            answer = max(answer,-sum);
        }
        if(j == sequence.size())
            break;
    }
    return answer;
}