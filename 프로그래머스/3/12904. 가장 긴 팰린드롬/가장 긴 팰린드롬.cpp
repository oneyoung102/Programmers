#include <string>

using namespace std;

int solution(string s)
{
    int answer = 0;
    const int n = s.size();
    for(int mid = 0 ; mid < n ; ++mid)
        for(int dist = 0 ;; ++dist)
            if(dist > mid || mid+dist >= n || s[mid-dist] != s[mid+dist])
            {
                answer = max(answer,1+2*(dist-1));
                break;
            }
    for(int i = 0 ; i < n-1 ; ++i)
        if(s[i] == s[i+1])
            for(int dist = 0 ;; ++dist)
                if(dist > i || i+1+dist >= n || s[i-dist] != s[i+1+dist])
                {
                    answer = max(answer,2*dist);
                    break;
                }
    return answer;
}