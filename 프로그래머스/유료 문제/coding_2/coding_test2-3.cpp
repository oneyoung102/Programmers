#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int C = 1e9+7;

int string_to_number(const string& n, int start, int end)
{
	int result = 0;
	for(int i = start ; i <= end  ; ++i)
		result = (result*10 + (n[i]-'0'))%C;
	return result;
}

void find_minimum(string& origin, vector<int>& p, int pos, int& mini, const int length)
{
	int n = 0;
	for(int i = 0 ; i < p.size()-1 ;++i)
	{
		if(p[i+1]-p[i] <= length+1)
			n += string_to_number(origin,p[i]+1,p[i+1]);
		else
		{
			n = -1;
			break;
		}
		if(n >= C)
			n %= C;
		if(n >= mini && mini != -1)
			break;
	}
	if((mini > n || mini == -1) && n != -1)
		mini = n;
	if(pos == 0)
		return;
	for(int i = 1 ; i <= p[pos+1]-p[pos]-length+1 ; ++i)
	{
		p[pos]+=i;
		if(p[pos+1]-p[pos] <= length+1 && p[pos+1]-p[pos] > 0)
			find_minimum(origin, p, pos-1 ,mini, length);
		p[pos]-=i;
	}
}
int solution(string num, int k)
{
	vector<int> plus_pos;
	const int length = num.size()/(k+1);
	plus_pos.push_back(-1);
	for(int i = 1 ; i <= k ; ++i)
		plus_pos.push_back(((length>1) ? length-1 : 1)*i-1);
	plus_pos.push_back(num.size()-1);
	int answer = -1;
	find_minimum(num, plus_pos,plus_pos.size()-2,answer, length);
	return answer;
}
int main()
{
	cout<<solution("8738122131243283742397482318593657983475987234954214",25);
	return 0;
}
