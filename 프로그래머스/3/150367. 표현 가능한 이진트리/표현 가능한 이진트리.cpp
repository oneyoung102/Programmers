#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

string get_binary_num(long long num)
{
    string bn = "";
    do{
        bn += num%2 +'0';
        num /= 2;
    }while(num != 0);

    int mult = 1, sum = 1;
    while(bn.size() > sum)
        sum += mult *= 2;
    const int plus = sum-bn.size();
    for(int i = 0 ; i < plus ; ++i)
        bn += '0';
    return bn;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(const long long number : numbers)
    {
        bool binary_tree_fy = true;
        const string bn = get_binary_num(number);
        queue<pair<unsigned long, unsigned long>> center_and_delta;
        center_and_delta.push(make_pair(bn.size()/2,(bn.size()/2+1)/2));
        while(!center_and_delta.empty())
        {
            const auto [center, delta] = center_and_delta.front();
            center_and_delta.pop();
            if(bn[center] == '0' && (bn[center-delta] == '1' || bn[center+delta] == '1'))
            {
                binary_tree_fy = false;
                break;
            }
            if(delta > 1)
            {
                center_and_delta.push(make_pair(center-delta,delta/2));
                center_and_delta.push(make_pair(center+delta,delta/2));
            }
        }
        
        answer.push_back((int)binary_tree_fy);
    }
    return answer;
}