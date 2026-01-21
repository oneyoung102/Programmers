#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> A, int S)
{
	int answer = 0;
	int first = 0, second = 0, sum = A[0];
	while(second < A.size())
	{
		if(sum == S)
		{
			answer++;
			second++;
			sum+=A[second];
		}
		else if(sum > S)
		{
			sum-=A[first];
			first++;
		}
		else if(sum < S)
		{
			second++;
			sum+=A[second];
		}
	}
	return answer;
}

int main()
{
	cout<<solution({1,1,3,1,1,1,2,2,1,2,3,5},4);
	return 0;
}
