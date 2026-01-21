#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l1, int l2) {
    vector<int> answer;

    int big = l1, small = l2;
    if(big < small)
        swap(big,small);

    int mult = 1;
    for(int i = small ; i >=2 ; --i)
    {
        if(small%i == 0 && big%i == 0)
        {
            mult *= i;
            small /= i;
            big /= i;
            if(small == 1)
                break;
        }
    }
    for(int i = mult ; i <= big*mult ; i += mult)
        answer.push_back(i);

    return answer;
}


int main()
{
    vector<int> test = solution(999,997);
    //999,17
    //10,3 
    for(int it : test)
        printf("%d,",it);
    return 0;
}
