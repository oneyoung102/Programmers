#include <string>
#include <vector>

using namespace std;

string calc(string& s)
{
    if(s == "") return "";
    int sum = 0, i = 0;
    bool is_correct_string = true;
    do
    {
        if(s[i] == '(')
            ++sum;
        else 
        {
            --sum;
            if(sum < 0) is_correct_string = false;
        }
        ++i;
    }while(sum != 0);
    
    string u = s.substr(0,i), v = s.substr(i);
    if(is_correct_string)
        return u + calc(v);
    else
    {
        u = u.substr(1,u.size()-2);
        for(auto& c : u)
            if(c == '(')
                c = ')';
            else
                c = '(';
        return '(' + calc(v) + ')' + u;  
    } 
}

string solution(string p) {
    return calc(p);
}