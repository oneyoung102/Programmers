#include <iostream>
#include <string>

// 11:58 ~ 12:11

using namespace std;

int solution(string s)
{
	int zero = 0;
	for(auto& it : s)
		if(it == '0')
			zero++;
	int one = s.size()-zero;
	for(int i = 0 ; i < s.size()-1 ; i++)
	{
		string str = s.substr(i,2);
		if(str == "01" || str == "10")
		{
			s.erase(i,2);
			zero--;
			one--;
			if(zero == 0 || one == 0)
				break;
			else
				i = (i>0) ? i-2 : -1;
		}
	}
	int answer = s.size();
	return answer;
}

int main()
{
	cout<<solution("00011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111");
	return 0;
}

