#include <cmath>
#include <utility>

using namespace std;

int get_reaves(int dist_limit, pair<int,int>&& factor1, pair<int,int>&& factor2)
{
    int sub_answer = 0; 
    int parent_dist_count = 1; //init : 루트 노드 자식 개수
    while((factor1.second > 0 || factor2.second > 0) && dist_limit >= 0)
    {
        const int CHILD_COUNT = (factor1.second > 0) ? factor1.first : factor2.first;
        if(factor1.second > 0)
            --factor1.second;
        else
            --factor2.second;

        if(dist_limit == 0) // 가장 깊은 노드에 도달
            return sub_answer + CHILD_COUNT*parent_dist_count;
        else
        {
            const int DIST_COUNT = fmin(parent_dist_count*CHILD_COUNT, dist_limit);
            dist_limit -= DIST_COUNT;
            sub_answer += CHILD_COUNT*parent_dist_count-DIST_COUNT;
            parent_dist_count = DIST_COUNT;
        }
    }
    return sub_answer + parent_dist_count;
}
int log3(unsigned int value)
{
    int exp = 0;
    while(value >= 3)
    {
        value /= 3;
        ++exp;
    }
    return exp;
}

int solution(int dist_limit, int split_limit) {
    if(dist_limit == 0)
        return 1;
    --dist_limit; //루트 로드에 소비

    int answer = 0;
    const int UPPER = log3(split_limit);
    for(int tc = 0, triple = 1 ; tc <= UPPER ; ++tc, triple *= 3)// 자식 노드 제한이 3인 깊이가 몇개
    {
        const int three_count = tc, two_count = log2(split_limit/triple);

        const int sub_answer = fmax(get_reaves(dist_limit,{3,three_count},{2,two_count})
                                   ,get_reaves(dist_limit,{2,two_count},{3,three_count}));
        answer = fmax(answer, sub_answer);
    }
    return answer;
}