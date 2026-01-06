#include <string>
#include <vector>
#include <set>

using namespace std;

template <typename T>
class double_priority_queue
{
    private :
        multiset<T> dpq;
    public :
        double_priority_queue(){};
        size_t size(){return this->dpq.size();};
        T get_min(){return *(this->dpq.begin());};
        T get_max(){return *(this->dpq.rbegin());};
        void pop_min(){if(!this->dpq.empty()) this->dpq.erase(this->dpq.begin());};
        void pop_max(){if(!this->dpq.empty()) this->dpq.erase(prev(this->dpq.end()));};
        void push(const T& t){this->dpq.insert(t);};
};

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    double_priority_queue<int> myDpq;
    for(const auto& s : operations)
        if(s[0] == 'I')
        {
            const int number = stoi(s.substr(2));
            myDpq.push(number);
        }
        else
        {
            if(s[2] == '1')
                myDpq.pop_max();
            else
                myDpq.pop_min();
        }
    if(myDpq.size() > 0)
        answer = {myDpq.get_max(),myDpq.get_min()};
    return answer;
}