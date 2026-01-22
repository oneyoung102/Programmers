#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    int num = 0;
    string numbers = "";
    while(numbers.size() < t*m)
    {
        string number = "";
        int sub_num = num;
        do
        {
            number += sub_num%n + ((sub_num%n < 10) ? '0' : 'A'-10);
            sub_num /= n;
        }while(sub_num != 0);
        for(auto it = number.rbegin() ; it < number.rend() ; ++it)
            numbers += *it;
        ++num;
    }
    string answer = "";
    for(int i = p-1, j = 0 ; j < t ; i += m,++j)
        answer += numbers[i];
    return answer;
}