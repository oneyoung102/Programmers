#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void calculate(string s, vector<string>& list, int index, bool erase)
{
	string str = s;
	if(index == str.size())
	{
		if(!erase)
			list.push_back(str);
		else 
			list.erase(remove(list.begin(),list.end(),str),list.end());
		return; 
	}
	if(str[index] == 'X')
	{
		for(char i = '0' ; i <= '9' ; i++)
		{
			str[index] = i;
			calculate(str, list, index+1, erase);	
		}
	}
	else
		calculate(str, list, index+1, erase);
}
vector<string> solution(string hope_number, vector<string> exist_number)
{
	vector<string> possible_number;
	calculate(hope_number,possible_number,0,false);
	for(const string& s : exist_number)
		calculate(s,possible_number,0,true);
	if(possible_number.size() == 0)
		return {"-1"};
	else
	{
		sort(possible_number.begin(),possible_number.end());
		return possible_number;
	}
}

int main()
{
	vector<string> vec = solution("123-4XX",{"123-4X0", "123-4X1", "123-4X2", "123-4X3", "123-4X4", "123-4X5", "123-4X7", "123-4X8", "123-4X9", "123-456", "123-49X"});
	for(int i = 0 ; i < vec.size() ; i++)
		cout<<vec[i]<<",";
	return 0;
}

