#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> trio_score(3,0);
    const vector<int> second_rule = {1,3,4,5};
    const vector<int> third_rule = {3,1,2,4,5};
    for(int i = 0 ; i < answers.size() ; ++i)
    {
        if(answers[i] == i%5+1)
            ++trio_score[0];
        if(i%2 == 0 && answers[i] == 2 || i%2 == 1 && answers[i] == second_rule[(i/2)%second_rule.size()])
            ++trio_score[1];
        if(answers[i] == third_rule[(i/2)%third_rule.size()])
            ++trio_score[2];
    }
    const int maxi = *max_element(trio_score.begin(),trio_score.end());
    for(int i = 0 ; i < trio_score.size() ; ++i)
        if(trio_score[i] == maxi)
            answer.push_back(i+1);
    return answer;
}