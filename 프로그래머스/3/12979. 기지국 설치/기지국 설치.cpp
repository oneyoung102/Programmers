#include <cmath>
#include <vector>

using namespace std;

int solution(int N, vector<int> stations, int w)
{
    const double W = 2*w+1;
    int answer = 0;
    if(stations.front() > w+1) answer += ceil((stations.front()-w-1)/W);
    for(int i = 1 ; i < stations.size() ; ++i)
    {
        const int n = stations[i]-stations[i-1]-2*w-1;
        if(n > 0) answer += ceil(n/W);
    }
    if(N-stations.back() > w) answer += ceil((N-stations.back()-w)/W);   
    return answer;
}