#include <map>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> young; int young_topping = 0;
    map<int,int> old; int old_topping = 0;
    for(const int t : topping)
        if(++old[t] == 1)
            ++old_topping;
    for(const int t : topping)
    {
        if(++young[t] == 1)
            ++young_topping;
        if(--old[t] == 0)
            --old_topping;
        if(young_topping == old_topping)
            ++answer;
    }
    return answer;
}