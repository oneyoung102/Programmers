#include <vector>
#include <string>
#include <iostream>

using namespace std;

void possible_block(int one, int pos, vector<vector<int>>& block, vector<vector<int> >& use,vector<vector<vector<int> > >& prob, vector<vector<int>>& tiles)
{
    int sum = 0;
    const int size = block.size();
    for(int i = 0 ; i < tiles.size() ; ++i)
    {
        for(int j = 0 ; j < tiles[0].size() ; ++j)
        {  
            if(use[i%size][j%size])
                ++sum;
            if(sum > one)
                return;
        }
    }
    if(sum == one)
        prob.push_back(use);
    if(pos < size*size)
        for(int i = 0; i < 2 ; i++)
        {
            use[pos/size][pos%size] = i;
            possible_block(one,pos+1,block,use,prob,tiles);
            use[pos/size][pos%size] -= i;
        }
    else
        return;
}
int calculate (int size, int one, vector<vector<int>>& tiles)
{
    vector<vector<int>> block(size,vector<int>(size,0));
    for(int i = 0 ; i < tiles.size() ; i++)
        for(int j = 0 ; j < tiles[0].size(); j++)
            ++block[i%size][j%size];
    vector<vector<vector<int>>> prob;
    vector<vector<int> > use(size,vector<int>(size,0));
    possible_block(one,0,block,use,prob,tiles);
    if(prob.size() == 0)
        return -1;
    int min = tiles.size()*tiles[0].size()/2;
    for(vector<vector<int> >& p : prob)
    {
        int gap = 0;
        for(int i = 0 ; i < tiles.size() ; i++)
            for(int j = 0 ; j < tiles[0].size(); j++)
                if(p[i%size][j%size] != tiles[i][j])
                    ++gap;
        if(gap/2 < min)
            min = gap/2;
    }
    return min;
}
int solution(vector<vector<int>> tiles)
{
    int one = 0;
    for(int i = 0 ; i < tiles.size() ; i++)
        for(int j = 0 ; j < tiles[0].size(); j++)
            if(tiles[i][j] == 1)
                ++one;
    int twotwo = calculate(2, one, tiles);
    if(twotwo == 0)
        return 0;
    int threethree = calculate(3, one, tiles);
    if(twotwo != -1 || threethree != -1)
    {
        if(twotwo < threethree && twotwo != -1)
            return twotwo;
        else if(threethree != -1)
            return threethree;
    }
    else
        return -1;
}
int main () {
    int a = solution({{0, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}});
    cout<<"result : "<<a<< endl;
    return 0;
}