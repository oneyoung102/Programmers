#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sort(mats.begin(), mats.end(),greater<int>());
    for(int i = 0 ; i < mats.size()&&answer==-1 ; i++)
    {
        for(int x = 0 ; x < park.size()-mats[i]+1&&answer==-1&&park.size()>=mats[i] ; x++)
        {
            for(int y = 0 ; y < park[0].size()-mats[i]+1&&answer==-1&&park[0].size()>=mats[i] ; y++)
            {
                int count = 0;
                for(int testx = 0 ; testx < mats[i] ; testx++)
                    for(int testy = 0 ; testy < mats[i] ; testy++)
                        if(park[testx+x][testy+y]=="-1")
                            count++;
                if(count == mats[i]*mats[i])
                    answer = mats[i];                        
            }
        }      
    }
    return answer;
}