#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int pos1 = 0;
    int pos2 = 0;
    for(const auto& it : goal)
    {
        if(cards1[pos1]==it)
            pos1++;
        else if(cards2[pos2]==it)
            pos2++;
        else
            return "No";
    }
    return "Yes";
}