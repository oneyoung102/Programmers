#include <string>
#include <vector>
#include <iostream>

using namespace std;
enum{notselected, selected, forbidden};
void find_case(vector<int> &st, vector<vector<int>>& set, vector<int>& q, int a, int pos, int count)
{   
    if(pos < q.size())
    {
        int* n = &st[q[pos]-1];
        if(*n == notselected)
        {
            if(count < a)
            {
                *n = selected;
                find_case(st,set,q,a, pos+1, count+1);
            }
            *n = forbidden;
            find_case(st,set,q,a, pos+1, count);
            *n = notselected;
        }
        else if(*n == selected)
            find_case(st,set,q,a, pos+1, count+1);
        else
            find_case(st,set,q,a, pos+1, count);
    }
    else if(count == a)
        set.push_back(st);
    return;
}
long long permutation(int n, int r)
{
    long long a = 1;
    for(int i = n-r+1 ; i <= n ; ++i)
        a*=i;
    return a;
}
int combination(int n, int r){return permutation(n,r)/permutation(r,r);}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    for(int it : ans)
        if(it == 5)
            return 1;
    vector<vector<vector<int>>> set(q.size(),vector<vector<int>>());
    vector<int> st(n,notselected);
    find_case(st,set[0],q[0],ans[0],0,0);
    for(int i = 1 ; i < set.size() ; ++i)
        for(int j = 0 ; j < set[i-1].size() ; ++j)
            find_case(set[i-1][j],set[i],q[i],ans[i],0,0);
    
    int answer = 0;
    for(vector<int> i : set[set.size()-1])
    {
        int select = 0, notselect = 0;
        for(int it : i)
            if(it == selected)
                ++select;
            else if(it == notselected)
                ++notselect;
        if(select <= 5 && notselect + select >= 5)
            answer += combination(notselect,5-select);
    }
    
    return answer;
}