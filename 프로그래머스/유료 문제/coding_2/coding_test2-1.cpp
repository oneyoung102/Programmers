#include <vector>
#include<iostream>

using namespace std;

//3:45 ~ 4:00

vector<int> solution(int n, vector<vector<int>> ladder)
{
	vector<int> pos;
	for(int i = 0 ; i < n ; i++)
		pos.push_back(i+1);
	for(int i = 0 ; i < pos.size() ; i++)
	{
		for(int j = 0 ; j < ladder.size() ; j++)
		{
			if(pos[i]>1&&ladder[j][pos[i]-2]==1)
				pos[i]--;
			else if(pos[i]<ladder[0].size()+1&&ladder[j][pos[i]-1]==1)
				pos[i]++;
		}
	}
	return pos;
}
int main()
{
	vector<vector<int>> l(5,vector<int>(3,0));
	l.push_back({1,0,1});
	l.push_back({0,1,0});
	l.push_back({0,0,1});
	l.push_back({0,0,0});
	l.push_back({1,0,0});

	for(const auto& it : solution(4,l))
		cout<<it<<" ";
	return 0;
}
