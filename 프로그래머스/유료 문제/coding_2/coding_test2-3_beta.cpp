#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int C = 1e9+7;

int to_int(string n)
{
    int sum = 0;
    for(char i : n)
        sum = (sum*10 + (i - '0'))%C;
    return sum%C;
}
int solution(string num, int k) {
    vector<int> poss_n_l;
    int middle_n = num.size()/(k+1);
    if(num.size()%(k+1) != 0)
    {
        if(middle_n != 1)
        {
            int the_others = num.size()-middle_n+1;
            if(the_others/k + ((the_others%k == 0) ? 0 : 1) - middle_n > 2)
                ++middle_n;
        }
        else
            ++middle_n;
    }
    if(middle_n != 1)
        poss_n_l.push_back(middle_n-1);
    poss_n_l.push_back(middle_n);
    if((middle_n != 1 || num.size()%(k+1) != 0) && k != 1)
        poss_n_l.push_back(middle_n+1);

    vector<vector<long long>> min_sum(num.size(),vector<long long>(k+1,LLONG_MAX));
    for(int i : poss_n_l)
        min_sum[i-1][0] = to_int(num.substr(0,i));
    for(int i = 1 ; i <= k ; ++i)
        for(int j = poss_n_l[0]*i ; j < num.size() ; ++j)
        {
                int l_start = j-poss_n_l.back();
                if(l_start < 0)
                    l_start = 0;
                for(int l = l_start ; l < j ; ++l)
                    if(min_sum[l][i-1] != LLONG_MAX)
                    {
                        long long candi = min_sum[l][i-1]+to_int(num.substr(l+1,j-l))%C;
                        if(candi < min_sum[j][i])
                            min_sum[j][i] = candi;
                    }
        }
    return int(min_sum[num.size()-1][k])%C;
}
            
int main()
{
	cout<<solution("728378127412728378127412471264126462196462194671276412674621214214413847283781274124712641264621964621946712764126746212142144138472837812741247126412646219646219467127641267462121421441384728378127412471264126462196462194671276412674621214214413847283781274124712641264621964621946712764126746212142144138472837812741247126412646219646219467127641267462121421441384728378127412471264126462196462194671276412674621214214413847283781274124712641264621964621946712764126746212142144138472837812741247126412646219646219467127641267462121421441384728378127412471264126462196462194671276412674621214214413847283781274124712641264621964621946712764126746212142144138447126412646219646219467127641267462121421441384",600);
	return 0;
}