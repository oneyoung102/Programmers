#include <string>
#include <vector>

using namespace std;

int tree(vector<vector<int>> w, vector<bool>& c,int n, int r)
{
    int count = 1;
    c[n] = true;
    for(int i = 0 ; i < w.size() ; i++)
        if(!c[i])
        {
            if(w[i][0] == w[n][r])
                count+= tree(w,c,i,1);
            else if(w[i][1] == w[n][r])
                count+= tree(w,c,i,0);
        }
    return count;
}


int solution(int n, vector<vector<int>> wires) {
    int min = n-1;
    for(int i = 0 ; i < wires.size() ; i++)
    {
        vector<bool> checked(wires.size(),false);
        int result = abs(n-2*tree(wires,checked,i,0));
        if(min > result)
            min = result;
    }    
    return min;
}