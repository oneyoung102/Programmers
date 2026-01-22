#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class expr_maxi
{
    private :
        const string comb[6] = {
            {"*+-"}, {"*-+"},
            {"+*-"}, {"+-*"},
            {"-*+"}, {"-+*"}
        };
        long long answer;
        list<long long> nums;
        list<char> opps;
    
        unordered_map<char,bool> opp_exist;
        void calc_expr(list<long long>& n, list<char>& o, const char opp)
        {
            for(auto p = o.begin() ; p != o.end() ;)
            {
                if(*p != opp)
                {
                    ++p;
                    continue;
                }
                const auto n1 = next(n.begin(),distance(o.begin(),p));
                const auto n2 = next(n1);
                if(opp == '*')
                    *n1 = *n1*(*n2);
                else if(opp == '+')
                    *n1 = *n1+(*n2);
                else
                    *n1 = *n1-(*n2);
                n.erase(n2);
                p = o.erase(p);
            }
        }
    public :
        expr_maxi(string& s)
        {
            answer = 0;
            int pos = -1;
            s += '+';
            for(int i = 0 ; i < (int)s.size() ; ++i)
                if(s[i] == '*' || s[i] == '+' || s[i] == '-')
                {
                    nums.push_back(stoll(s.substr(pos+1,i-pos-1)));
                    pos = i;
                    opps.push_back(s[i]);
                    opp_exist[s[i]] = true;
                }
            nums.push_back(0);
        }
        long long get_maxi()
        {
            for(const auto& s : comb)
            {
                list<long long> n = nums;
                list<char> o = opps;
                for(const auto& c : s)
                    if(opp_exist[c])
                        calc_expr(n,o,c);
                answer = max(answer,abs(n.front()));
            }
            return answer;
        }
};
long long solution(string expression) {
    expr_maxi EM(expression);
    return EM.get_maxi();
}