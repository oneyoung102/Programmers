#include <string>
#include <vector>
#include <iostream>

using namespace std;

void calculate(string s, vector<string>& list, int index)
{
	string str = s;
	if(index == str.size())
	{
		list.push_back(str);
		return; 
	}
	if(str[index] == 'X')
	{
		for(char i = '0' ; i <= '9' ; i++)
		{
			str[index] = i;
			calculate(str, list, index+1);	
		}
	}
	else
		calculate(str, list, index+1);
}
vector<string> solution(string hope_number, vector<string> exist_number)
{
	vector<string> possible_number;
	vector<int> xpos, npos;
	for(int i = 0 ; i < hope_number.size() ; i++)
	{
		if(hope_number[i] == 'X')
			xpos.push_back(i);
		else if(hope_number[i] != '-')
			npos.push_back(i);
	}
	for(int k = 0 ; k < exist_number.size() ; k++)
	{
		for(int i : npos)
		{
			char& deta = exist_number[k][i];
			if(deta != hope_number[i])
			{
				if(deta == 'X')
					deta = hope_number[i];
				else if(deta != '-')
					exist_number.erase(exist_number.begin()+k--);
			}
		}
	}
	calculate(hope_number,possible_number,0);
	for(int k = 0 ; k < possible_number.size() ; k++)
		for(int j = 0 ; j < exist_number.size() ; j++)
		{
			int ncount = 0;
			int samecount = 0;
			for(int i : xpos)
			{
				if(exist_number[j][i] != 'X')
				{
					++ncount;
				if(exist_number[j][i] == possible_number[k][i])
					++samecount;
				}
			}
			if(ncount == samecount)
			{
				possible_number.erase(possible_number.begin()+k--);
				break;
			}
		}
				
	if(possible_number.size() == 0)
		return {"-1"};
	else
		return possible_number;
}

int main()
{
	vector<string> vec = solution("123-4XX",{"123-4X0", "123-4X1", "123-4X2", "123-4X3", "123-4X4", "123-4X5", "123-4X7", "123-4X8", "123-4X9", "123-456", "123-49X"});
	for(int i = 0 ; i < vec.size() ; i++)
		cout<<vec[i]<<",";
	return 0;
}

