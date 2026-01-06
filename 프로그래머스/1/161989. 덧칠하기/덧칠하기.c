#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// section_len은 배열 section의 길이입니다.
int solution(int n, int m, int section[], size_t section_len) {
    int answer = 0;
    for(int i = 1 ; i < n+1 ; i++)
        for(int j = 0 ; j < section_len ; j++)
            if(section[j]==i)
            {
                for(int k = m ; k > 0 ; k--)
                    for(int q = j ; q < section_len ; q++)
                        if(i+k-1==section[q])   
                        {
                            answer++;
                            i+=k-1;
                            k=0;
                            break;
                        }
                break;
            }
    return answer;
}