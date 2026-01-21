#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

void find_link(map<string, int>& searchB, vector<string>& before, vector<string>& after, int pos, int& answer, int start)
{
	if(before[pos] != after[pos] && searchB[after[pos]] != 0)
	{
		searchB[before[pos]] = 0;
		find_link(searchB,before,after,searchB[after[pos]]-1,answer,start);
	}
	else if(pos == start&&searchB[after[pos]] == 0)
	{
		++answer;
		return;
	}
}
int solution(vector<string> before, vector<string> after)
{
	map<string, int> searchB;
	for(int i = 0 ; i < before.size() ; ++i)
		searchB[before[i]] = i+1;
	int answer = before.size();
	for(int i = 0 ; i < before.size() ; i++)
		if(before[i] == after[i])
			--answer;
		else if(searchB[before[i]] != 0 && searchB[after[i]] != 0)
			find_link(searchB,before,after,searchB[after[i]]-1,answer,i);	
	return answer; 
}
int main()
{
	cout << solution({"A", "B", "C","D","E","F","G","H"}, {"B", "D", "F","G","C","H","E","A"});
	return 0;
}
