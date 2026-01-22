#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    vector<int> users = players;
    for(int i = 0 ; i < users.size() ; ++i)
    {
        const int server = users[i]/m;
        if(server >= 1)
        {
            for(int j = i ; j < i+k && j < users.size() ; ++j)
                users[j] -= (users[j] < server*m) ? users[j] : server*m;
            answer += server;
        }
    }
    return answer;
}