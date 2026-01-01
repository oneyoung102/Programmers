#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int count_same(const string& s1, const string& s2)
{
    int same = 0;
    const int n = min(s1.size(),s2.size());
    for(int i = 0 ; i < n ; ++i)
    {
        if(s1[i] != s2[i])
            break;
        ++same; 
    }
    return same;
}

int solution(vector<string> words) {
    const int N = words.size();
    int answer = 0;
    sort(words.begin(),words.end());
    int prev_same_count = 0;
    for(int i = 0 ; i < N-1 ; ++i)
    {
        const int same = count_same(words[i],words[i+1]);
        answer += min(max(prev_same_count,same)+1,(int)words[i].size());
        prev_same_count = same;
    }
    answer += prev_same_count+1;
    return answer;
}
