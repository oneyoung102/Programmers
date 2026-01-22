#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    sort(data.begin(),data.end(),[col](const vector<int>& v1, const vector<int>& v2){
        if(v1[col-1] < v2[col-1])
            return true;
        if(v1[col-1] == v2[col-1])
            return v1[0] > v2[0];
        return false;     
    });
    vector<int> S_i;
    for(int i = row_begin-1 ; i < row_end ; ++i)
    {
        int sum = 0;
        for(const int d : data[i])
            sum += d%(i+1);
        S_i.push_back(sum);
    }
    int XOR = S_i[0];
    for(int i = 1 ; i < S_i.size() ; ++i)
        XOR ^= S_i[i];
    return XOR;
}