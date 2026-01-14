#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> category_sort;
    for(const auto& c : clothes)
        ++category_sort[c[1]];
    for(const auto& cs : category_sort)
        answer *= cs.second+1;
    return answer-1;
}