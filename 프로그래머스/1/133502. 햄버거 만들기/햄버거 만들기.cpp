#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    for(int i = 0 ; i < ingredient.size()-3 ; i++)
        if(ingredient.size() > 3+i)
        {
            if(ingredient[i] == 1 && ingredient[i+1] == 2 && ingredient[i+2] == 3 && ingredient[i+3] == 1)
            {
                answer++;
                ingredient.erase(ingredient.begin()+i,ingredient.begin()+i+4);
                i = (i>2) ? i-4 : -1;
            }
        }
        else
            break;
            
    return answer;
}