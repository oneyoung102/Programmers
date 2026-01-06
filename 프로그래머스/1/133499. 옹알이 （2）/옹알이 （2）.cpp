#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    for(auto& it :  babbling)
    {
        int pronounce = -1;
        while(1)
        {
            if(it.substr(0,3)=="aya" && pronounce != 0)
            {
                it.erase(it.begin(),it.begin()+3);
                pronounce = 0;
            }
            else if(it.substr(0,3)=="woo" && pronounce != 1)
            {
                it.erase(it.begin(),it.begin()+3);
                pronounce = 1;
            }
            else if(it.substr(0,2)=="ye" && pronounce != 2)
            {
                it.erase(it.begin(),it.begin()+2);
                pronounce = 2;
            }
            else if(it.substr(0,2)=="ma" && pronounce != 3)
            {
                it.erase(it.begin(),it.begin()+2);
                pronounce = 3;
            }
            else if(it.size() == 0)
            {
                answer++;
                break;
            }
            else
                break;
        }
    }
    return answer;
}