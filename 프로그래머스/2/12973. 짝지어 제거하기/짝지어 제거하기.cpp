#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    if(s.size()%2 == 1)
        return 0;

    vector<int> st;
    for(const char c : s)
    {
        if(!st.empty() && st.back() == c)
            st.pop_back();
        else
            st.push_back(c);
    }
    return st.empty();
}