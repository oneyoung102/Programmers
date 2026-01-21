#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<string> arr1, vector<string> arr2) {
    long long answer = 0;
    map<int,int> ParenthesisGap1, ParenthesisGap2;
    
    for(string& it : arr1)
    {
        int count = 0;
        for(auto c = it.begin()  ; c < it.end() ; ++c)
            if(*c == '(')
                ++count;
            else
            {
                if(count == 0)
                {
                    --ParenthesisGap1[count];
                    break;
                }
                --count;
            }        
        ++ParenthesisGap1[count];
    }
    for(string& it : arr2)
    {
        int count  = 0;
        for(auto c = it.rbegin()  ; c < it.rend() ; ++c)
            if(*c == '(')
            {
                if(count == 0)
                {
                    --ParenthesisGap2[count];
                    break;
                }
                --count;
            }
            else
                ++count;    
        ++ParenthesisGap2[count];
    }
    for(auto it = ParenthesisGap1.begin() ; it != ParenthesisGap1.end() ; ++it)
    {
        const int value = ParenthesisGap2[(*it).first];
        if(value != 0)
            answer += (*it).second*value;
    }
    return answer;
}

int main()
{
    printf("%lld",solution({"()", "(()", ")()", "()","()", "(()", ")()", "()","()", "(()", ")()", "()","()", "(()", ")()", "()"},{")()", "()", "(()",")()", "()", "(()",")()", "()", "(()",")()", "()", "(()",")()", "()", "(()"}));
    //{"()", "(()", ")()", "()"},{")()", "()", "(()"}
    //{"()", "(()", "(", "(())"},{")()","()", "(())", ")()"}
    return 0;
}