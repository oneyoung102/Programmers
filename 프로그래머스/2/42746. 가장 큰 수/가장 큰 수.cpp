#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct mysort
{
    bool operator()(const string& s1, const string& s2)
    { 
        return s1+s2 > s2+s1;
    };
};

string solution(vector<int> numbers) {
    vector<string> sub_numbers(numbers.size());
    transform(numbers.begin(),numbers.end(),sub_numbers.begin(),[](int x) -> string{
        return to_string(x);
    });
    sort(sub_numbers.begin(),sub_numbers.end(),mysort());
    string answer = accumulate(sub_numbers.begin(),sub_numbers.end(),string());
    if(answer[0] == '0')
        answer = "0";
    return answer;
}