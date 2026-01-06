#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    map<string,int> gem_count;
    for(const string& g : gems)//보석 종류 확인
        gem_count[g] = 0;
    
    const int types = gem_count.size();
    const int all_gems = gems.size();
    int curr_types = 0, left = 0, right = -1;
    vector<int> answer = {1,all_gems};
    while(left+types-1 < all_gems)
    {
        if(curr_types < types && right+1 < all_gems)
        {
            if(gem_count[gems[++right]]++ == 0)
                ++curr_types;
        }
        else
        {
            if(curr_types >= types && right-left < answer[1]-answer[0])
                answer = {left+1,right+1};
            if(--gem_count[gems[left++]] == 0)
                --curr_types;
        }
    }
    return answer;
}