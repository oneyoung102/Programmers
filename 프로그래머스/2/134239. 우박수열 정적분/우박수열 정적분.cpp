#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> nums;
    vector<double> area;
    nums.push_back(k);
    while(k != 1)
    {
        if((k&1) == 0)
        {
            area.push_back(0.75*k);
            k /= 2;
        }
        else    
        {
            area.push_back(2*k+0.5);
            k = k*3 + 1;
        }
        nums.push_back(k);
    }
    const int left = 0, right = area.size();
    for(vector<int>& it : ranges)
    {
        const int al = it[0], ar = right+it[1];
        if(al < left || al > ar)
            answer.push_back(-1.0);
        else
        {
            double area_sum = 0;
            for(int i = al ; i < ar ; ++i)
                area_sum += area[i];
            answer.push_back(area_sum);
        }
    }
    return answer;
}