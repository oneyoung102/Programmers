#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int fold_poss_sign = false;
    while(fold_poss_sign == false)
    {
        
        if((wallet[0]>=bill[0]&&wallet[1]>=bill[1])||(wallet[0]>=bill[1]&&wallet[1]>=bill[0]))
        {
            fold_poss_sign = true;
            break;
        }
        else
        {
            if(bill[0]>bill[1])
                bill[0]*=0.5;
            else
                bill[1]*=0.5;
        }
        answer++;
    }
    return answer;
}