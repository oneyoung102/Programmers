#include <string>
#include <vector>

using namespace std;

int solution(vector<int> openA, vector<int> closeB)
{
	int answer = 0;
	bool opened = true;
	int a = 0, b = 0;
	closeB.push_back(openA.back()+1);
	openA.push_back(closeB.back()+1);
	while(a < openA.size() || b < closeB.size())
	{
		if(openA[a] < closeB[b])
		{
			if(opened)
				answer+=closeB[b]-openA[a];
			if(a < openA.size())
				++a;
			opened = false;
		}
		else
		{
			if(b < closeB.size())
				++b;
			opened = true;
		}
	}
	return answer;
}
int main()
{
	int s = solution({3,5,7},{4,10,12});
	printf("%d",s);
	return 0;
}
