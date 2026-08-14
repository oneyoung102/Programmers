#include <cmath>
#include <vector>

using namespace std;

vector<long long> solution(vector<int> arr, long long l, long long r) {
    long long K = 0, C = 0;
    
    int arr_idx = 0;
    long long brr_idx = 0;
    for(; arr_idx < arr.size() ; ++arr_idx)
    {
        brr_idx += arr[arr_idx];
        if(brr_idx >= l)
        {
            K += (brr_idx-l+1)*arr[arr_idx];
            break;
        }
    }
    if(brr_idx >= r)
        K -= (brr_idx-r)*arr[arr_idx];
    else
    {
        ++arr_idx;
        for(; arr_idx < arr.size() ; ++arr_idx)
        {
            K += (long long)arr[arr_idx]*arr[arr_idx];
            brr_idx += arr[arr_idx];
            if(brr_idx >= r)
            {
                K -= (brr_idx-r)*arr[arr_idx];
                break;
            }
        }
    }
    
    const long long K_length = r-l+1;
    
    int left = 0, right = 0;
    long long sum = 0;
    long long length = 0;
    
    while(left < arr.size())
    {          
        if(length <= K_length)
        {
            if(sum == K && length == K_length)  
                ++C;
            if(right >= arr.size())
                break;
        }
        else
        {
            const long long  a = arr[left];
            const long long  b = arr[right-1];
            if(sum > K)
            {
                const long long count = length - K_length;
                // a*x + b*(count-b) = sum-K;
                
                if(a == b)
                {
                    if(sum-K == count*a)
                        if(left == right-1)
                        {
                            if(count < a)
                                C += count+1;
                        }
                        else
                        {
                            if(count < 2*a-1)
                                C += 2*min(count,a-1)-count+1;
                        }
                }
                else
                {
                    const long long numer = sum-K-count*b; 
                    const long long denom = a-b;
                    if(numer%denom == 0)
                    {
                        const long long x = numer/denom;
                        if(0 <= x && x < a
                        && 0 <= count-x && count-x < b)
                            ++C;
                    }
                }
            }
        }
        
        bool expand = true;
        if(length >= K_length)
            expand = length-arr[left]+2 <= K_length;
        if(sum >= K)
            expand = sum-(long long)arr[left]*(arr[left]-1)+arr[right] <= K;
        
        if(expand && right < arr.size())
        {
            sum += (long long)arr[right]*arr[right];
            length += arr[right];
            ++right;
        }
        else
        {
            sum -= (long long)arr[left]*arr[left];
            length -= arr[left];
            ++left; 
        }
    }
    
    
    return {K,C};
}