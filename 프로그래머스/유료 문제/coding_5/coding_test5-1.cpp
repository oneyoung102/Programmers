#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> solution(vector<int> people)
{
	vector<int> answer;
	map<string, int> pizza;
	for(int p : people)
		if(++pizza[to_string(p)]%4 == 0)
			answer.push_back(p);
	if(answer.size() == 0)
		answer.push_back(-1);
	return answer;
}

int main(void)
{
	for(int a : solution({1,1,3,3}))
		printf("%d",a);
	return 0;
}
