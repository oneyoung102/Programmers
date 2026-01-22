#include <string>
#include <vector>
#include <climits>

using namespace std;

int tired(int pick, string minerals)
{
    int m = 0;
    if(minerals == "diamond")
        m = 2;
    else if(minerals == "iron")
        m = 1;
    if(m - pick == 1)
        return 5;
    else if(m - pick == 2)
        return 25;
    else
        return 1;
}
int total_tired(vector<int>& picks, vector<string>& minerals, int pos, int total)
{
    static int min = INT_MAX;
    if((pos >= minerals.size() || picks[0]+picks[1]+picks[2] == 0)&& min > total)
        min = total;
    else
    {
        for(int p = 0 ; p < picks.size() ; ++p)
        {
            if(picks[p] > 0)
            {
                --picks[p];
                int t = 0;
                for(int i = pos ; i < pos +5 && i < minerals.size() ; ++i)
                    t += tired(picks.size()-p-1,minerals[i]);
                total_tired(picks,minerals,pos+5,total+t);
                ++picks[p];
            }
        }
    }
    return min;
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    answer = total_tired(picks,minerals,0,0);
    return answer;
}