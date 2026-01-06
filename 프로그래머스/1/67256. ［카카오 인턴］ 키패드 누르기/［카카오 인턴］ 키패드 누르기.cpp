#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftpos = 10, rightpos = 12;
    for(auto& it : numbers)
        if(it == 0)
            it = 11;
    for(const auto& it : numbers)
    {
        if(it == 1 || it == 4 || it == 7)
        {
            leftpos = it;
            answer.push_back('L');
        }
        else if(it == 3 || it == 6 || it == 9)
        {
            rightpos = it;
            answer.push_back('R');
        }
        else if(it == 2 || it == 5 | it == 8 || it == 11)
        {
            if(abs(leftpos-it)/3+abs(leftpos-it)%3 > abs(rightpos-it)/3+abs(rightpos-it)%3)
            {
                rightpos = it;
                answer.push_back('R');
            }
            else if(abs(leftpos-it)/3+abs(leftpos-it)%3 < abs(rightpos-it)/3+abs(rightpos-it)%3)
            {
                leftpos = it;
                answer.push_back('L');
            }
            else
            {
                if(hand == "right")
                {
                    rightpos = it;
                    answer.push_back('R');
                }
                else
                {
                    leftpos = it;
                    answer.push_back('L');
                }
            }
        }
    }
    return answer;
}