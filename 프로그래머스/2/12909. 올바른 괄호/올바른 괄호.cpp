#include <string>

using namespace std;

bool solution(string s)
{
    if(s.size()%2 == 1)
        return false;
    int count = 0;
    for(const auto c : s)
        if(c == '(')
            ++count;
        else 
        {
            if(count == 0)
                return false;
            --count;  
        }
    if(count == 0)
        return true;
    return false;
}