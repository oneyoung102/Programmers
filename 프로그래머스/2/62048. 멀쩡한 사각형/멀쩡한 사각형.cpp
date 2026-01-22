long long solution(int w,int h) {
    long long answer = 0;
    for(long long i = 1 ; i < w ; ++i)
        answer += i*h/w;
    return answer*2;
}