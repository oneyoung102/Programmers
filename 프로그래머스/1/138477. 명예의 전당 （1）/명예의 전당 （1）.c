#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    int* answer = (int*)malloc(score_len*sizeof(int));
    int mini=2000;
    for(int i=0 ; i<score_len ; i++)
    {
        int max = 0;
        for(int j=0 ; j<i+1 ; j++)
            if(max<score[j])
                max = score[j];
        int count = 0;
        for(int q=0 ; q<max+1 ; q++)
        {
            for(int p=0 ; p<i+1 ; p++)
                if(max-q == score[p])
                {
                    count+=1;
                    if((count == 1+i&&i<k)||(count == k&&i>=k))
                    {
                         answer[i] = score[p];
                        q=max+1;
                        break;
                    }
                }
        }
    }
    return answer;
}