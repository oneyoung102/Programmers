#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int* solution(const char* wallpaper[], size_t wallpaper_len) {
    int minmax[4] = {wallpaper_len-1,strlen(wallpaper[0]),0,0};
    for(int i = 0 ; i<wallpaper_len ; i++)
    {
        for(int j = 0 ; j<strlen(wallpaper[i]) ; j++)
            if(wallpaper[i][j]=='#')
            {
                minmax[0]=(i<minmax[0]) ? i : minmax[0];
                minmax[2]=i>(minmax[2]) ? i :minmax[2] ;  
                minmax[1]=(j<minmax[ 1]) ? j : minmax[1];
                minmax[3]=j>(minmax[3]) ? j :minmax[3] ;  
            }
    }
    int* answer = (int*)malloc(4*sizeof(int));
    for(int j = 0 ; j<4 ; j++)
        answer[j]=(j>1) ? minmax[j]+1 : minmax[j];
    return answer;
}