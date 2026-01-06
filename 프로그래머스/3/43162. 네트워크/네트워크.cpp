#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> checked(n,false);
    for(int i = 0 ; i < n ; ++i)
    {
        if(checked[i])
            continue;
        ++answer;
        queue<int> network;
        network.push(i);
        while(!network.empty())
        {
            const int start = network.front();
            network.pop();
            checked[start] = true;
            for(int j = 0 ; j < n ; ++j)
                if(!checked[j] && computers[j][start] == 1)
                    network.push(j);
        }
    }
    return answer;
}