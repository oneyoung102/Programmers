#include <string>
#include <vector>
#include <climits>

using namespace std;

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    auto comparing = [](int& min, int com){
        if(min > com)
            min = com;
    };
    for(vector<int>& it : balls)
    {
        const int dx = startX-it[0], dy = startY-it[1], mdx = startX+it[0], mdy = startY+it[1];
        int min = INT_MAX, comp;
        if(startY != it[1] || startX < it[0]) comparing(min, mdx*mdx + dy*dy);
        if(startX != it[0] || startY < it[1]) comparing(min, dx*dx + mdy*mdy);
        if(startY != it[1] || startX > it[0]) comparing(min, (2*m-mdx)*(2*m-mdx) + dy*dy);
        if(startX != it[0] || startY > it[1]) comparing(min, dx*dx + (mdy-2*n)*(mdy-2*n));
        answer.push_back(min);
    }
    return answer;
}