#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(2*sizeof(int));
    int dog[2];
    for(int i=0; i<strlen(park[0]) ; i++)
        for(int j=0; j<park_len ; j++)
        {
            if(park[j][i] == 'S')
            {
                dog[0] = i;
                dog[1] = j;
                break;
            }
        }
    for(int i=0; i<routes_len ; i++)
    {
        int move;
        if(routes[i][0]=='N'||routes[i][0]=='S')
        {
            move = ((routes[i][0]=='S') ? 1 : -1)*atoi(&routes[i][2]);
            if(dog[1]+move<park_len&&dog[1]+move>=0)
            {
                int cnt=0;
                for(int j=0 ; j<abs(move) ; j++)
                     if(park[dog[1]+move/abs(move)*(j+1)][dog[0]]=='X')
                     {
                          cnt+=1;
                          break;
                     }
                if(cnt==0)
                    dog[1]+=move;
            }
        }
        else
        {
            move = ((routes[i][0]=='E') ? 1 : -1)*atoi(&routes[i][2]);
            if(dog[0]+move<strlen(park[0])&&dog[0]+move>=0)
            {
                int cnt=0;
                for(int j=0 ; j<abs(move) ; j++)
                     if(park[dog[1]][dog[0]+move/abs(move)*(j+1)]=='X')
                     {
                          cnt+=1;
                          break;
                     }
                if(cnt==0)
                    dog[0]+=move;
            }
        }     
    }
            
    answer[0] = dog[1];
    answer[1] = dog[0];
    // printf("%d, %d",&dog[0],&dog[1]);
    return answer;
}