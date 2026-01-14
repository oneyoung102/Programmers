#include <string>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    const int original_s_size = s.size();
    for(int i = 0 ; i < original_s_size ; ++i)
    {
        bool complete = true;
        stack<char> st;
        for(int j = i ; j < s.size() ; ++j)
        {
            if(!st.empty() &&(
                st.top() == '(' && s[j] == ')' ||
                st.top() == '{' && s[j] == '}' ||
                st.top() == '[' && s[j] == ']'
            ))
                st.pop();
            else
                st.push(s[j]);
        }
        if(st.empty())
            ++answer;
        s.push_back(s[i]);
    }
    return answer;
}