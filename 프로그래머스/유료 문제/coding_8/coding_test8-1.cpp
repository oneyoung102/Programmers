#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool PinC(vector<double> center, double radian, vector<int> point)
{
    const double dx = (center[0]-point[0]), dy = (center[1]-point[1]);
    return dx*dx+dy*dy <= radian*radian;
}

int solution(vector<int> x, vector<int> y) {
    vector<vector<int>> coord;
    for(int i = 0 ; i < x.size() ; ++i)
        coord.push_back({x[i],y[i]});
    sort(coord.begin(), coord.end(), [](vector<int> a, vector<int> b){
        return a[0] < b[0];
    });

    int answer = 0;
    for(int i = 0 ; i < coord.size()-1 ; ++i)
    {
        vector<int> p1 = coord[i];
        for(int j = i+1 ; j < coord.size() ; ++j)
        {
            vector<int> p2 = coord[j];

            vector<double> center = {((double)(p1[0])+p2[0])/2,((double)(p1[1])+p2[1])/2};
            double dx = (p2[0]-center[0]), dy = (p2[1]-center[1]), radian = sqrt(dx*dx+dy*dy);

            bool sign1 = true;
            auto inTest = [&coord,&center,&radian](int k) -> bool
            {
                return coord[k][1] >= center[1]-radian && coord[k][1] <= center[1]+radian && PinC(center,radian,coord[k]);
            };
            for(int k = i+1 ; k < coord.size() && coord[k][0] <= center[0]+radian && k != j ; ++k)
            {
                if(inTest(k))
                {
                    sign1 = false;
                    break;
                }
            }
            if(sign1)
            {
                bool sign2 = true;
                for(int k = i-1 ;  k >= 0 && coord[k][0] >= center[0]-radian ; --k)
                    if(inTest(k))
                    {
                        sign2 = false;
                        break;
                    }
                if(sign2)
                    ++answer;
            }
        }
    }
    return answer;
}
int main()
{
    printf("%d",solution({1,2,6,8},{1,2,6,8}));//{0,0,1,1},{0,1,0,1}
    return 0;
}
