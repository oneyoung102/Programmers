#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    sort(weights.begin(),weights.end());
    for(int i = 0 ; i < weights.size() ; i++)
        for(int j = i+1 ; j < weights.size() ; j++)
        {
            float divide = static_cast<float>(weights[j])/static_cast<float>(weights[i]);
            if(divide == 2 || divide == 1.5 || static_cast<float>(weights[j])/4 == static_cast<float>(weights[i])/3 || divide == 1)
                answer++;
            else if(divide > 2)
                break;
        }
    return answer;
}