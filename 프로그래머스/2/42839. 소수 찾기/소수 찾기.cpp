#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

set<int> combi;
void combination(const string& prev_num, const string& num_set)
{
    for(int i = 0 ; i < num_set.size() ; ++i)
    {
        const string next_num = prev_num+num_set[i];
        combi.insert(stoi(next_num));
        const string next_num_set = num_set.substr(0,i)+num_set.substr(i+1);
        combination(next_num,next_num_set);
    }
}

int solution(string numbers) {
    const string prev_num = "";
    combination(prev_num,numbers);
    
    int answer = 0;
    for(const auto n : combi)
    {
        if(n != 2 && n%2 == 0 || n == 1)
            continue;
        bool is_prime = true;
        for(int i = 3 ; i <= (int)sqrt(n) ; i += 2)
            if(n%i == 0)
            {
                is_prime = false;
                break;
            }
        if(is_prime)
            ++answer;
    }
    return answer;
}