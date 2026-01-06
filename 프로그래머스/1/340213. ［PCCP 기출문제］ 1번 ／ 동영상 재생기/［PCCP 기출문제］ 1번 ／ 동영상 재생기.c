#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int StringToInt(const char* ch)
{
    int var[4];
    for(int i = 0 ; i<4 ; i++)
        var[i] = ch[(i<2)? i : i+1] - '0';
    return (var[0]*10+var[1])*60+var[2]*10+var[3];
}
// commands_len은 배열 commands의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* video_len, const char* pos, const char* op_start, const char* op_end, const char* commands[], size_t commands_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char)*5);
    int VIDEOLEN = StringToInt(video_len);
    int POS = StringToInt(pos);
    int OPSTART = StringToInt(op_start);
    int OPEND = StringToInt(op_end);
    for(int i = 0 ; i<commands_len ; i++)
    {
        if(OPSTART<=POS&&POS<=OPEND)
            POS = OPEND;
        if(strcmp(commands[i],"next")==0)
            POS+=(POS+10<VIDEOLEN) ? 10 : VIDEOLEN-POS;
        else if(strcmp(commands[i],"prev")==0)
            POS-=(POS-10>0) ? 10 : POS;
    }
    if(OPSTART<=POS&&POS<=OPEND)
        POS = OPEND;
    answer[0] = POS/600+'0';
    answer[1] = (POS/60)%10+'0';
    answer[2] = ':';
    answer[3] = (POS%60)/10+'0';
    answer[4] = (POS%60)%10+'0';
    answer[5] = '\0';
    return answer;
}