#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> nums) {
    vector<int> snacks;
    auto push_snack = [&snacks](int c, int gram){
        for(int i = 0 ; i < c ; ++i)
            snacks.push_back(gram);
    };
    for(int i = 0 ; i < nums.size() ; ++i)
        push_snack(nums[i],i+1);

    vector<int> answer;
    const int snacks_amount_mid = snacks.size()/2-1;
    for(int i = snacks[snacks_amount_mid]+1 ; i < snacks[snacks_amount_mid+1] ; ++i)
        answer.push_back(i);
    if(!answer.empty())
        return answer;
    return {-1};
}

int main()
{
    vector<int> n = solution({1, 1, 1});
    for(int it : n)
        printf("%d,",it);
    //{1, 0, 0, 1, 1}
    //{0, 4, 0, 4, 0}
    //{1, 1, 1}
    return 0;
}