#include <string>
#include <vector>

using namespace std;
void position(pair<int,int>& p, int n, int w)
{
    p.second = (n-1)/w;
    if(p.second%2 == 0)
        p.first = (n-1)%w;
    else
        p.first = w-(n-1)%w-1;
}
int solution(int n, int w, int num) {
    int answer = 0;
    pair<int,int> number,last;
    position(number,num,w);
    position(last,n,w);
    
    answer += last.second - number.second+1;
    if(last.second%2 == 0)
    {
        if(last.first < number.first)
            --answer;
    }
    else
    {
        if(last.first > number.first)
            --answer;
    }
    return answer;
}