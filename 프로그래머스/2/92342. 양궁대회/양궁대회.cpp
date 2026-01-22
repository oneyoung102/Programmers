#include <string>
#include <vector>

using namespace std;

vector<int> answer = {-1};
int max_score_gap = 0;
vector<int> global_info;

void calc(int a_score, int r_score, int n, int p, vector<int>& test)
{
    if(p == -1)
    {
        if(max_score_gap < r_score-a_score)
        {
            max_score_gap = r_score-a_score;
            answer = test;
            answer.back() += n;
        }
        return;
    }         
    if(n >= global_info[p]+1)
    {
        test[p] = global_info[p]+1;
        if(global_info[p] == 0)
            calc(a_score,r_score+10-p,n-1,p-1,test);
        else
            calc(a_score-10+p,r_score+10-p,n-global_info[p]-1,p-1,test);   
        test[p] = 0;
    }
    calc(a_score,r_score,n,p-1,test);           
    return;
}
vector<int> solution(int n, vector<int> info) {
    global_info = info;
    int a_score = 0;
    for(int i = 0 ; i < info.size()-1 ; ++i)
        a_score += (info[i] != 0) ? 10-i : 0;
    vector<int> test(11,0);
    calc(a_score,0,n,9,test);
    return answer;
}