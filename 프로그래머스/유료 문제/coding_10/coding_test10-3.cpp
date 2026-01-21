#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<int> solution(int l1, int l2) {
    vector<int> answer;
    set<int> candidate;
    candidate.insert(l1);
    candidate.insert(l2);

    int big = l1, small = l2;
    if(big < small)
        swap(big,small);

    for(int i = small*2 ; i < big ; i += small)
        candidate.insert(i);
        
    queue<int> another_cand;
    another_cand.push(0);
    while(!another_cand.empty())
    {
        int afford = small-another_cand.front();
        for(int i = big-afford ; i > 0 ; i -= afford)
        {
            if(candidate.find(i) == candidate.end())
            {
                candidate.insert(i);
                if(i < small)
                    another_cand.push(i);
            }
            if(afford != small)
                afford = small; 
        }
        another_cand.pop();
    }  
    for(auto it : candidate)
        answer.push_back(it);
    
    return answer;
}


int main()
{
    vector<int> test = solution(8,18);
    //999,17
    //10,3 
    for(int it : test)
        printf("%d,",it);
    return 0;
}