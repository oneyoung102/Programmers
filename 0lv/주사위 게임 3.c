//2024-07-25 19:08:56
//https://school.programmers.co.kr/learn/courses/30/lessons/181916

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int amount[7]={0,0,0,0,0,0,0};
    amount[a]++;amount[b]++;amount[c]++;amount[d]++;
    for(int i=1;i<7;i++)
    {
        if(amount[i]==4)
        {
            answer=1111*i;
            break;
        }
        else if(amount[i]==3)
        {
            for(int j=1;j<7;j++)
            {
                if(amount[j]==1)
                {
                    answer=(10*i+j)*(10*i+j);
                    break;
                }
            }  
            break;
        }
        else if(amount[i]==2)
        {
        for(int j=1;j<7;j++)
        {
                if(amount[j]==2&&j!=i)
                {
                    answer=(i+j)*abs(i-j);
                }
                else if(amount[j]==1)
                {
                    for(int k=1+j;k<7;k++)
                    {
                        if(amount[k]==1)
                        {
                            answer=k*j; 
                            break;
                        }
                    }
                }
         }
            break;
        }
        else if(amount[i]==1)
        {
            int mini=7;
            for(int j=1;j<7;j++)
            {             
                if(amount[j]==1)
                {
                     if(mini>j)
                         mini=j;
                }
                else if(amount[j]>1)
                {
                    mini=7;
                    break;
                }
            }
            if(mini!=7)
            {
                 answer=mini;
                 break;
            }  
        }
    }
    
    return answer;
}
