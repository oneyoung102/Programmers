#include <string>
#include <vector>

using namespace std;
int answer = 0;
vector<vector<int>> dun;
void explore(int count, int k)
{ 
    for(int i = 0 ; i < dun.size() ; ++i)
    {
        const int mini = dun[i][0];
        if(k >= mini)
        {
            const int decrement = dun[i][1];
            dun.erase(dun.begin()+i);
            explore(count+1,k-decrement);
            dun.insert(dun.begin()+i,{mini,decrement});
        }
    }
    answer = max(answer,count);
}
int solution(int k, vector<vector<int>> dungeons) {
    for(const auto& d : dungeons)
        dun.push_back(d);
    explore(0,k);
    return answer;
}