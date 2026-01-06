#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    const long long criteria = stoll(p);
    const int length = p.size();
    for(int i = 0 ; i < t.size()-length+1 ; ++i)
        if(stoll(t.substr(i,length)) <= criteria)
            ++answer;
    return answer;
}