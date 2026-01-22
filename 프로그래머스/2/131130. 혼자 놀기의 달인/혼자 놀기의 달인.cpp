#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> cards) {
    multiset<int> group_length;
    for(int c : cards)
    {
        if(c == -1)
            continue;
        int length = 0;
        int next = c;
        do
        {
            const int temp = cards[next-1];
            cards[next-1] = -1;
            next = temp;
            ++length;
        }while(next != c);
        group_length.insert(length);
    }
    if(group_length.size() > 1)
    {
        auto it = prev(group_length.end());
        return (*it)*(*prev(it));
    }
    else
        return 0;
}