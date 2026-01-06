#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// friends_len은 배열 friends의 길이입니다.
// gifts_len은 배열 gifts의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* friends[], size_t friends_len, const char* gifts[], size_t gifts_len) {
    int present_array[friends_len][friends_len]; //raw : 준 사람, col : 받은 사람
    for(int i = 0 ; i < friends_len ; i++)
        for(int j = 0 ; j < friends_len ; j++)
            present_array[i][j] = 0;
    int present_num[friends_len];
    for(int i = 0 ; i < friends_len ; i++)
        present_num[i] = 0;
    
    int present_amount[friends_len];
    for(int i = 0 ; i < friends_len ; i++)
        present_amount[i] = 0;
////////////////////////////////////////////////////////////////////////
    for(int i = 0 ; i < gifts_len ; i++)
    {
        char name[2][10];
        for(int j = 0 ; j < 2 ; j++)
            for(int k = 0 ; k < 10 ; k++)
                name[j][k]=' ';
        int nf = 0;
        while(gifts[i][nf]!=' ')
        {
            name[0][nf] = gifts[i][nf];
            nf++;
        }
        nf++;
        int ns = 0;
        while(nf+ns < strlen(gifts[i]))
        {
            name[1][ns] = gifts[i][nf+ns];
            ns++;
        }
        int name_num[2] = {-1,-1};
        for(int t = 0 ; t < 2 ; t++)
        {
            for(int j = 0 ; j < friends_len ; j++)
            {
                int detect = 0;
                int name_length = 0;
                for(int k = 0 ; k < 10 ; k++)
                    if(name[t][k] != ' ')
                        name_length++;
                for(int k = 0 ; k < strlen(friends[j]) ; k++)
                    if(friends[j][k] != name[t][k]||strlen(friends[j])!=name_length)
                    {
                        detect = 1;
                        break;
                    }
                if(detect == 0)
                {
                    name_num[t] = j;
                    break;
                }      
            }
        }
        present_array[name_num[0]][name_num[1]]++;
        present_num[name_num[0]]++;
        present_num[name_num[1]]--;
    }
    
    int present_relationship[friends_len][friends_len];
    for(int i = 0 ; i < friends_len ; i++)
        for(int j = 0 ; j < friends_len ; j++)
            present_relationship[i][j] = 0;
    
    for(int i = 0 ; i < friends_len ; i++)
    {
        for(int j = 0 ; j < friends_len && j!=i && present_relationship[i][j] == 0 && present_relationship[j][i] == 0; j++)
        {
            if(present_array[i][j]>present_array[j][i])
                present_amount[i]++;
            else if(present_array[i][j]<present_array[j][i])
                present_amount[j]++;
            else
            {
                if(present_num[i]>present_num[j])
                present_amount[i]++;
                else if(present_num[i]<present_num[j])
                present_amount[j]++;
            }
            present_relationship[i][j]++;
            present_relationship[j][i]++;
        }
    }
    
    int answer = 0;
    for(int i = 0 ; i < friends_len ; i++)
    {
        if(present_amount[i]>answer)
            answer = present_amount[i];
    }
    return answer;
}