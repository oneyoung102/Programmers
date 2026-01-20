#include <vector>

using namespace std;

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    const long long N = 4e14;//2e9<금,은> x 1e5<최대 편도 시간> x 2<왕복>
    long long answer = N, left = 0, right = N;
    while(left <= right)
    {
        const long long mid = (left+right)/2;
        long long sub_a = 0, sub_b = 0, convert_b = 0;
        for(int i = 0 ; i < t.size() ; ++i)
        {
            const int get = (int)min((long long)(2e9),(mid/t[i]+1)/2*w[i]);
            const int a_get = min(g[i],get), b_get = min(s[i],get-a_get);
            sub_a += a_get;
            sub_b += b_get;
            convert_b += min(a_get,s[i]-b_get);
        }
        if(sub_a >= a && sub_b + min(sub_a-a,convert_b) >= b)
        {
            answer = min(answer,mid);
            right = mid-1;
        }
        else
            left = mid+1;
    }
    return answer;
}