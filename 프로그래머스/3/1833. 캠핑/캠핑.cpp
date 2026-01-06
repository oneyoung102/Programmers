#include <vector>
#include <algorithm>
#include <set>

using namespace std;
using coord = vector<int>;

enum{
    row,
    col
};
bool test_pin_in_tent(vector<set<int>>& col_by_row, const int col_big, const int col_small, int i, int j)
{
    for(int k = i+1 ; k < j ; ++k)
    {
        auto it = col_by_row[k].upper_bound(col_small);
        if(it != col_by_row[k].end() && *it < col_big)
            return false;   
    }
    return true;
}

struct compare{
    bool operator()(coord f, coord s){
        if(f[row] < s[row])
            return true;
        return false;
    }
};

int solution(int n, vector<coord> data) {
    int answer = 0;
    vector<set<int>> col_by_row;
    int prev_row = -1;
    sort(data.begin(),data.end(),compare());   
    for(coord& d : data)
        if(prev_row != d[row])
        {
            col_by_row.push_back({d[col]});
            prev_row = d[row];
        }
        else
            col_by_row.back().insert(d[col]);

    for(int i = 0 ; i < col_by_row.size()-1 ; ++i)
        for(int c1 : col_by_row[i])
        {
            for(int j = i+1 ; j < col_by_row.size() ; ++j)
            {
                bool prev_test_not_passed = false;
                int prev_col_small = c1;
                for(int c2 : col_by_row[j])
                {
                    if(c1 == c2)
                        continue;
                    if(c1 < c2)
                    {
                        if(prev_test_not_passed)
                            continue;
                        const int col_big = c2;
                        const int col_small = prev_col_small;
                        if(test_pin_in_tent(col_by_row,col_big,col_small,i,j))
                            ++answer;
                        else
                            prev_test_not_passed = true;
                        prev_col_small = col_big-1;
                    }
                    else
                    {
                        const int col_big = c1;
                        const int col_small = c2;
                        if(test_pin_in_tent(col_by_row,col_big,col_small,i,j))
                            ++answer;
                    }
                }
            }
        }   
    return answer;
}