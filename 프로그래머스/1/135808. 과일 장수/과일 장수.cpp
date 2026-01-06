#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    sort(score.begin(),score.end(),greater());
    int answer = 0;
    for(int i = 1 ; m*i-1 < score.size() ; ++i)
        answer += score[m*i-1]*m;
    return answer;
}