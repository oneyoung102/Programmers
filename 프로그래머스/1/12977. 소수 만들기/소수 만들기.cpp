#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    const int s = nums.size();
    for(int i = 0 ; i < s-2 ; ++i)
        for(int j = i+1 ; j < s-1 ; ++j)
            for(int k = j+1 ; k < s ; ++k)
            {
                ++answer;
                const int num = nums[i]+nums[j]+nums[k];
                for(int n = 2 ; n <= (int)sqrt(num) ; ++n)
                    if(num%n ==0)
                    {
                        --answer;
                        break;
                    }
            }
    return answer;
}