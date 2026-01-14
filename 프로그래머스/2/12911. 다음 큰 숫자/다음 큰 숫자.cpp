#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
    string digit = "";
    while(n != 0)
    {
        digit += n%2+'0';
        n /= 2;
    }    
    digit += '0';
    
    int answer = 0, before_count = 0;
    bool change_pos_find = false;
    for(int i = 0 ; i < digit.size()-1 ; ++i)
        if(digit[i] == '1')
        {
            if(change_pos_find)
                answer += pow(2,i);
            else
            {
                if(digit[i+1] == '0')
                {
                    change_pos_find = true;
                    answer += pow(2,i+1) + pow(2,before_count)-1;
                }
                else
                    ++before_count;
            }
        }
    return answer;
}