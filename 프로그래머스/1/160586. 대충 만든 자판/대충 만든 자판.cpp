#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    for(int t = 0 ; t < targets.size() ; t++)
    {
        for(int i = 0 ; i < targets[t].size() ; i++)
        {
            int minimum = 101;
            for(int j = 0 ; j < keymap.size() ; j++)
            {
                for(int k = 0 ; k < keymap[j].size() ; k++)
                {
                    if(keymap[j][k] == targets[t][i])
                    {
                        if(k<minimum)
                            minimum = k;
                    }
                }
            }
            if(minimum == 101)
            {
                answer[t] = -1;
                break;
            }
            else
                answer[t] += minimum+1;
        }
    }
    return answer;
}