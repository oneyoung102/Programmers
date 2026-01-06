#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<float> failO;
    for(int i=0 ; i<N ; i++)
    {
        float sum=0;
        for(int j=i ; j<N+1 ; j++)
            sum+=count(stages.begin(),stages.end(),j+1);
        failO.push_back(static_cast<float>(count(stages.begin(),stages.end(),i+1))/((sum==0) ? 1 : sum));        
    }
    vector<float> failR(failO);
    sort(failR.begin(),failR.end(),greater<float>());
    for(int i=0 ; i<N ; i++)      
        for(int j=0 ; j<N ; j++)  
            if(failR[i]==failO[j]&&count(failR.begin(),failR.begin()+i+1,failR[i])==count(failO.begin(),failO.begin()+j+1,failR[i]))
            {
                answer.push_back(j+1);
                break;
            }
    
    return answer;
}