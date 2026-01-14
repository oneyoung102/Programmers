#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    const int list_size = want.size();
    unordered_map<string,int> want_list;
    for(int i = 0 ; i < list_size ; ++i)
        want_list[want[i]] = number[i];
    
    unordered_map<string,int> disc_list;
    int i = 0, j = -1, answer = 0, same = 0;
    while(j < (int)discount.size())
    {
        if(j-i == 9)
        {
            if(same == list_size)
                ++answer;
            const string s = discount[i++];
            if(disc_list[s]-- == want_list[s])
                --same;
        }
        else
        {
            if(++j == (int)discount.size()) break;
            const string s = discount[j];
            if(++disc_list[s] == want_list[s])
                ++same;
        }
    } 
    return answer;
}