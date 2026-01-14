#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2,0);
    while(s != "1")
    {
        int count[2] = {0,};
        for(const auto c : s)
            ++count[c-'0'];

        string new_s = "";
        while(count[1] != 0)
        {
            new_s.push_back(count[1]%2+'0');
            count[1] /= 2;
        }
        reverse(new_s.begin(),new_s.end());
        s = new_s;

        ++answer[0];
        answer[1] += count[0];
    }
    return answer;
}