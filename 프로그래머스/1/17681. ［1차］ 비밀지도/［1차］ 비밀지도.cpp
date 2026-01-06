#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n,"");
    for(int i = 0 ; i < arr1.size() ; ++i)
    {
        int num = 1;
        for(int j = 0 ; j < n ; ++j)
        {
            if((arr1[i] & num)|(arr2[i] & num) >= 1)
                answer[i] += "#";
            else
                answer[i] += " ";
            num *= 2;
        }
        reverse(answer[i].begin(), answer[i].end());
    }
    return answer;
}