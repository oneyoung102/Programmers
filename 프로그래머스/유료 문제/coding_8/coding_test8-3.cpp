#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool CinC(vector<int>& c1, vector<int>& c2)
{
    const long long sqx = c1[0]-c2[0], sqy = c1[1]-c2[1];
    const double length = sqrt(sqx*sqx+sqy*sqy);
    return length + c1[2] <= c2[2];
}

int solution(vector<vector<int>> circles) {
    sort(circles.begin(),circles.end(),[](vector<int>& a, vector<int>& b){
        return a[2] < b[2];
    });
    vector<bool> checked(circles.size(),false);
    int max = 1;
    for(int i = 0 ; i < circles.size()-max ; ++i)
    {
        if(!checked[i])
        {
            int count_in_cir = 1;
            vector<int> compare_cir = circles[i];
            checked[i] = true;
            for(int j = i+1 ; j < circles.size() ; ++j)
            {
                if(CinC(compare_cir,circles[j]))
                {
                    ++count_in_cir;
                    compare_cir = circles[j];
                    checked[j] = true;
                }
            }
            if(count_in_cir > max)
                max = count_in_cir;
        }
    }
    return max;
}

int main()
{
    printf("%d",solution({{-4,0,2},{-4,0,4},{-4,0,6},{2,0,8}}));
    return 0;
}
