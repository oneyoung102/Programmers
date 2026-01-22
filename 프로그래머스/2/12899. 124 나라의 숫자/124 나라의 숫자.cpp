#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string number = "";
    while(n > 0)
    {
        number.push_back((n%3 == 0) ? '4' : n%3 +'0');
        n = (n - ((n%3 == 0) ? 3 : n%3))/3;
    }
    string answer = "";
    for(int i = number.size()-1 ; i >=0  ; i--)
        answer.push_back(number[i]);
    return answer;
}