#include <string>
#include <vector>
#include <cmath>

using namespace std;
void one_counting(int level, long long l, long long r, int& count)
{
    static vector<long long> fives(level,-1);
    const long long sqfive = pow(5,level-1);
    for(int i = 1 ; i <= 5 ; ++i)
        if(i != 3 && l <= sqfive*i)
        {
            if(l > sqfive*(i-1)+1 && l <= sqfive*i && r > sqfive*(i-1)+1 && r <= sqfive*i)
            {
                one_counting(level-1,l-sqfive*(i-1),r-sqfive*(i-1),count);
                break;
            }
            else if(l > sqfive*(i-1)+1 && l <= sqfive*i)
                one_counting(level-1,l-sqfive*(i-1),sqfive,count);
            else if(r > sqfive*(i-1)+1 && r <= sqfive*i)
            {
                one_counting(level-1,1,r-sqfive*(i-1),count);
                break;
            }
            else if(l == sqfive*i || r == sqfive*(i-1)+1)
            {
                ++count;
                if(r == sqfive*(i-1)+1)
                    break;
            }
            else
            {
                if(fives[level-1] == -1)
                    fives[level-1] = pow(4,level-1);
                count += fives[level-1];
            }
        }
        else if(i == 3 && r <= sqfive*i)
            break;
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    one_counting(n,l,r,answer);
    return answer;
}

