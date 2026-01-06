#include <vector>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int max = 0;
    for(auto& it : nums)
        if(max<it)
            max = it;
    vector<int> amount(max,0);
    for(auto& it : nums)
        amount.at(it-1) += 1;
    int kind = amount.size();
    for(auto& it : amount)
        if(it == 0)
            kind--;
    answer = (kind>nums.size()/2) ? nums.size()/2 : kind;
    return answer;
}