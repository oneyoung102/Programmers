#include <string>
#include <vector>
#include <limits.h>
#include <map>

using namespace std;
 
int solution(vector<string> tickets, int roll, vector<vector<string>> shop, int money) {
    int answer = 0;
    int case_size = shop[0].size();
    map<string,int> pay;
    for(string& s : tickets)
    {
        int i = 0;
        while(s[i] != ' ')
            ++i;
        pay[s.substr(0,i)] = stoi(s.substr(i));
    }
    vector<int> goods;
    for(int i = 0 ; i < shop.size() ; ++i)
        for(int j = 0 ; j < case_size ; ++j)
                goods.push_back(pay[shop[i][j]]+i*roll);
    int roll_start = 1;
    while(1)
    {
        int pos = 0;
        int buy = INT_MAX;
        for(int i = goods.size()-1 ; i >= 0 ; --i)
            if(buy > goods[i] && goods[i] != -1)
            {
                buy = goods[i];
                pos = i;
            }
        int case_pos = pos/case_size;
        if(money >= buy)
        {
            money -= buy;
            ++answer;
            if(money == 0)
                break;
        }
        else 
            break;
        if(pos >= roll_start*case_size)
        {
            for(int i = roll_start*case_size ; i < goods.size() ; ++i)
            {
                if(goods[i] != -1)
                {
                    if(i< case_pos*case_size)
                        goods[i] -= (i/case_size-roll_start+1)*roll;
                    else
                        goods[i] -= (case_pos-roll_start+1)*roll;
                }
            }
            roll_start = case_pos+1;
        }
        goods[pos] = -1;
    }
    return answer;
}
int main()
{
    int a = solution({"A 2", "B 1"},1,{{"A", "A", "A"}, {"A", "B", "B"}, {"A", "B", "B"}, {"A", "B", "B"}},6);
   printf("%d",a);
    return 0;
}