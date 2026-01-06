#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s)
        return {-1};
    vector<int> answer(n,s/n);
    const int rest = s%n;
    for(int i = 0 ; i < rest ; ++i)
        ++answer[answer.size()-i-1];
    return answer;
}