#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// bandage_len은 배열 bandage의 길이입니다.
// attacks_rows는 2차원 배열 attacks의 행 길이, attacks_cols는 2차원 배열 attacks의 열 길이입니다.
int solution(int bandage[], size_t bandage_len, int health, int** attacks, size_t attacks_rows, size_t attacks_cols) {
    int answer = 0;
    int totalHealth = 0;
    int sequence = 0;
    int attack_count = 0;
    for(int i=0; attack_count<attacks_rows ;i++)
    {
        if(i+1==*attacks[attack_count])
        {
            totalHealth-=*(attacks[attack_count]+1);
            sequence=0;
            attack_count++;
        }
        else
        {
            for(int j = 0 ; j<bandage[1]&&totalHealth<0 ; j++)
                totalHealth++;  
            sequence++;
            if(sequence==bandage[0])
            {
                for(int j = 0 ; j<bandage[2]&&totalHealth<0 ; j++)
                    totalHealth++;
                sequence=0;
            } 
        }
        if(-totalHealth>=health)
        {
            answer = -1;
            break;
        }
        if(attack_count==attacks_rows)
            answer = health+totalHealth;
    }   
    
    //answer = *(attacks[0]+1);
    return answer;
}