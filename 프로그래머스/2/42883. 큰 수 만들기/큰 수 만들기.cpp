#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    const int len = number.size()-k;
    int big_pos = -1;
    for(int j = 1 ; j <= len ; ++j)
    {
        char big = 0;
        for(int i = big_pos+1 ; i < number.size()-len+j ; ++i)
        {
            if(number[i] > big)
            {
                big = number[i];
                big_pos = i;
                if(big == '9')
                    break;
            }
        }   
        answer += big;
    }
    return answer;
}