#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = (int)s.size();
    for(int i = 1 ; i <= (int)s.size()-1 ; ++i)
    {
        int length = 0, unit_count = 1;
        string prev_text = s.substr(0,i), curr_text = "";
        int j = i;
        while(j < s.size())
        {
            curr_text = (i+j < s.size()) ? s.substr(j,i) : s.substr(j);

            if(curr_text == prev_text)
                ++unit_count;
            else
            {
                length += (int)(prev_text.size()) + ((unit_count != 1) ? (int)(to_string(unit_count).size()) : 0);
                if(i+j < s.size())
                    prev_text = curr_text;
                unit_count = 1;
            }
            j += i;
        }
        length += (int)(curr_text.size()) + ((curr_text == prev_text) ? (int)(to_string(unit_count).size()) : 0);
        answer = min(answer,length);
    }
    return answer;
}