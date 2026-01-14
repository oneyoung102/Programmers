#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2,0);
    set<string> words_set;
    words_set.insert(words.front());
    for(int i = 1 ; i < words.size() ; ++i)
    {
        const bool used = (words_set.end() != find(words_set.begin(),words_set.end(),words[i]));
        if(used || words[i-1].back() != words[i].front())
        {
            answer = {i%n+1,i/n+1};
            break;
        }
        words_set.insert(words[i]);
    }
    return answer;
}