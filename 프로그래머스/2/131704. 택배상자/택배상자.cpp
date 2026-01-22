#include <stack>
#include <vector>

using namespace std;

int solution(vector<int> order) {
    const int total_box = order.size();
    stack<int> main_container;
    for(int i = total_box ; i >= 1 ; --i)
        main_container.push(i);
    stack<int> sub_container;
    int i = 0;
    while(i < total_box)
    {
        if(!main_container.empty() && order[i] == main_container.top())
        {
            ++i;
            main_container.pop();
        }
        else if(!sub_container.empty() && order[i] == sub_container.top())
        {
            ++i;
            sub_container.pop();
        }
        else
        {
            if(main_container.empty())
                return i;
            sub_container.push(main_container.top());
            main_container.pop();
        }
    }
    return total_box;
}