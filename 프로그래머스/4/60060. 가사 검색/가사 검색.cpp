#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    const int N = words.size();
    sort(words.begin(),words.end());
    vector<vector<string>> dictionary_greater(10001),dictionary_less(10001);
    for(const string& word : words)
        dictionary_greater[word.size()].push_back(word);

    for(string& word : words)
        reverse(word.begin(),word.end());
    sort(words.begin(),words.end());
    for(const string& word : words)
        dictionary_less[word.size()].push_back(word);

    vector<int> answer;
    for(string& query : queries)
    {
        const int len = query.size();
        vector<string>* dict = &(dictionary_greater[len]);
        if(query.front() == '?' && query.back() == '?')
        {
            answer.push_back((*dict).size());
            continue;
        }
        if(query.front() == '?')
        {
            dict = &(dictionary_less[len]);
            reverse(query.begin(),query.end());
        }
        const int idx = distance(query.begin(),find(query.begin(),query.end(),'?'));
        const string obvious = query.substr(0,idx);
        string vague = obvious;
        vague[vague.size()-1] += 1;
        const auto low = lower_bound((*dict).begin(),(*dict).end(),obvious), upp = upper_bound(low,(*dict).end(),vague);
        answer.push_back(upp-low);
    }
    return answer;
}