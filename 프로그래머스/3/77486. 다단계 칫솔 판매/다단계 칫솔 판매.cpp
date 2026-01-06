#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    unordered_map<string,int> numbering;
    int n = 0;
    for(const auto& name : enroll)
        numbering[name] = n++;
    vector<int> interests(enroll.size(),0);
    queue<pair<int,int>> numbers;
    for(int i = 0 ; i < seller.size() ; ++i)
        numbers.push(make_pair(numbering[seller[i]],amount[i]*100));
    while(!numbers.empty())
    {
        const auto [num, interest] = numbers.front();
        numbers.pop();
        const int rest = interest/10;
        interests[num] += interest-rest;
        if(rest != 0 && referral[num] != "-")
            numbers.push(make_pair(numbering[referral[num]],rest));    
    }
    return interests;
}