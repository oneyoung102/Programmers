#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int same = 0;
    int diff = 0;
    for(int i = 0 ; i < lottos.size() ; i++)      
        for(int j = 0 ; j < win_nums.size() ; j++)
            if(lottos[i] == win_nums[j])
            same++;
    for(auto& it : lottos)
        if(it == 0)
            diff++;
    answer.push_back((same+diff<=1) ? 6 : 7-same-diff);
    answer.push_back((same<=1) ? 6 : 7-same);
    return answer;
}