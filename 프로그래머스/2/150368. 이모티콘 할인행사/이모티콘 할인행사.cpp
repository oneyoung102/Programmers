#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class perfect_sale
{
    private :
        vector<vector<int>> Users;
        vector<int> Emoticons;
        vector<int> Answer;
        vector<int> Sale_ratio;
    public :
        perfect_sale(vector<vector<int>> u, vector<int> e)
        {
            Users = u;
            Emoticons = vector<int>(e.size());
            transform(e.begin(),e.end(),Emoticons.begin(),[](int x){
                return x/100;
            });
            Answer = vector<int>(2,0);
            Sale_ratio = vector<int>(e.size(),0);
        }
        void comparing_answer();
        void calc_saling(int n);
        vector<int> get_answer();
};
void perfect_sale::comparing_answer()
{
    int emoticon_plus = 0, emoticon_incentive = 0;
    for(const auto& v : Users)
    {
        int personal_emoticon_incentive = 0;
        for(int i = 0 ; i < Emoticons.size() ; ++i)
            if(Sale_ratio[i] >= v[0])
            {
                personal_emoticon_incentive += Emoticons[i]*(100-Sale_ratio[i]);
                if(personal_emoticon_incentive >= v[1])
                {
                    personal_emoticon_incentive = 0;
                    ++emoticon_plus;
                    break;
                }
            }
        emoticon_incentive += personal_emoticon_incentive;
    }
    if(Answer[0] < emoticon_plus)
        Answer = {emoticon_plus,emoticon_incentive};
    else if(Answer[0] == emoticon_plus)
        Answer[1] = max(Answer[1],emoticon_incentive);
}
void perfect_sale::calc_saling(int n)
{
    if(n == Emoticons.size())
    {
        comparing_answer();
        return;
    }
    for(int i = 10 ; i <= 40 ; i += 10)
    {
        Sale_ratio[n] = i;
        calc_saling(n+1);
    }
}
vector<int> perfect_sale::get_answer()
{
    return Answer;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    perfect_sale PS(users,emoticons);
    PS.calc_saling(0);
    return PS.get_answer();
}