#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(string& x : s)
    {
        int count_110 = 0;
        string temp = "";
        for (char c : x) {
            temp += c;
            if (temp.size() >= 3 && temp.substr(temp.size()-3) == "110") {
                temp.erase(temp.end()-3, temp.end());
                ++count_110;
            }
        }
        x = std::move(temp);
        int last_perfact_pos = x.size();
        string accumulate_x = "";
        for(int k = 0 ; k < x.size() ; ++k)
            if(x[k] == '1' && (k+1 == x.size() || x[k+1] == '1'))
            {
                last_perfact_pos = k;
                break;
            }
        accumulate_x += x.substr(0, last_perfact_pos);
        for(int k = 0 ; k < count_110 ; ++k)
            accumulate_x += "110";
        accumulate_x += x.substr(last_perfact_pos);
        answer.push_back(accumulate_x);
    }
    return answer;
}