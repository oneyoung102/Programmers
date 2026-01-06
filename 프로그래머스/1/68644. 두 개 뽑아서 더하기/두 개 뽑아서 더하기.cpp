#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> numbers_set;
    for(int i = 0 ; i < numbers.size()-1 ; ++i)
        for(int j = i+1 ; j < numbers.size() ; ++j)
            numbers_set.insert(numbers[i]+numbers[j]);
    vector<int> answer(numbers_set.begin(), numbers_set.end());
    return answer;
}