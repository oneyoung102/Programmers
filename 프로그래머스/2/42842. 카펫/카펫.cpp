#include <utility>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    const int total = brown+yellow;
    int r = 1, c = total;
    while(r*c != total|| (r-2)*(c-2) != yellow)
    {
        ++r;
        c = total/r;
    }
    if(r < c)
        swap(r,c);
    return {r,c};
}