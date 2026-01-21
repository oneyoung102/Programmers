#include <string>

using namespace std;

//12:15 ~ 12:45

bool solution(string s, string cipher)
{
	bool answer = true;
	char correspond[26];
	bool occupied[26];
	for(int i = 0 ; i < 26 ; i++)
	{
		correspond[i] = '0';
		occupied[i] = false;
	}
	for(int i = 0 ; i < s.size()&&answer ; i++)
	{
		int pos = s[i]-'a';
		if(correspond[pos] == '0')
		{
			correspond[pos] = cipher[i];
			if(occupied[cipher[i]-'a'])
				answer = false;
			else
				occupied[cipher[i]-'a'] = true;
		}
		else if(correspond[pos] != cipher[i])
			answer = false;
	}
	return answer;
}
int main()
{
	if(solution("world","abcde"))
		printf("true");
	else
		printf("false");
	return 0;
}

