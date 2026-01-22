#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class culinary
{
    private :
        vector<string> answer;
        vector<map<string,int>> menu;
        vector<string> orders;
        vector<int> course;

        void combination(string& order, int pos, string& comb, int count);
        void push_menu();
        void make_culinary();
    public :
        culinary(vector<string>& o, vector<int>& c)
        {
            menu = vector<map<string,int>>(c.back()+1);
            orders = o;
            for(auto& order : orders)
                sort(order.begin(),order.end());
            course = c;
        }
        vector<string> get_answer();
};
void culinary::combination(string& order, int pos, string& comb, int count)
{
    if(comb.size() == count)
    {
        ++menu[count][comb];
        return;
    }
    if(pos >= order.size())
        return;
    comb.push_back(order[pos]);
    combination(order,pos+1,comb,count);
    comb.pop_back();
    combination(order,pos+1,comb,count);
}
void culinary::push_menu()
{
    for(string& order : orders)
        for(const int count : course)
        {
            if(order.size() < count)
                break;
            string comb = "";
            combination(order,0,comb,count);
        }
}
void culinary::make_culinary()
{
    push_menu();
    for(const auto& m : menu)
    {
        int max_order = 2;
        vector<string> candidate;
        for(auto it = m.begin() ; it != m.end() ; ++it)
        {
            if(max_order <= it->second)
            {
                if(max_order < it->second)
                {
                    candidate = vector<string>();
                    max_order = it->second;
                }
                candidate.push_back(it->first);
            }
        }
        for(const string& s : candidate)
            answer.push_back(s);
    }
}
vector<string> culinary::get_answer(){
    make_culinary();
    sort(answer.begin(),answer.end());
    return answer;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    culinary Cul(orders,course);
    return Cul.get_answer();
}