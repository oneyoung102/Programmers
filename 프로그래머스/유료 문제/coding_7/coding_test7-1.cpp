#include <vector>
using namespace std;
 
int solution(vector<int> win_lose)
{
    int answer = 0;
    int sequence = 0;
    for(int i = 0 ; i < win_lose.size() ; ++i)
    {
        if(win_lose[i] == 1 )
        {
            ++sequence;
            if(sequence > answer)
                answer = sequence;
        }
        else
            sequence = 0;
    }
    return answer;
}
int main()
{
    int a = solution({0,1,0,1,1,1,0,1,1,1,1});
    printf("%d",a);
}
 