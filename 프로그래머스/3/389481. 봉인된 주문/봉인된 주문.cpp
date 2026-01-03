#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> banned;
    for(string str : bans)
    {
        long long num = 0;
        long long var = 0;
        for(int i = str.size()-1 ; i >= 0  ; --i)
        {
            var = (str[i]-'a'+1) * pow(26,str.size()-i-1);
            num += var;
        }
        banned.push_back(num);
    }
    sort(banned.begin(),banned.end());
    for(long long l : banned)
        if(l <= n)
            ++n;
    
    while(n >= 1)
    {
        answer += 'a' + (n+25)%26;
        n -= (n%26 == 0) ? 26 : n%26;
        n/=26;
    }
    reverse(answer.begin(),answer.end());
    return answer;
}