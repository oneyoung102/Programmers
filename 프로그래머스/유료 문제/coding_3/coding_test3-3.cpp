#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> weather, int k)
{
	int max = 0;
	for(int i = 1 ; i <= k ; i++)
	{
		vector<int> w(weather.begin(),weather.end());
		int answer = w.size();
		for(int j = 1 ; j < w.size()-i+1 ; j++)
		{
			if(w[j+i-1]-w[j-1] == -1)
			{
				w[j+i-1] = 1;
				answer-=1;
			}
			else if(w[j+i-1]-w[j-1] == 1)
			{
				w[j+i-1] = 0;
				answer-=1;
			}
		}
		if(answer < w.size()/2)
			answer = w.size()-answer;
		if(max < answer)
		{
			max = answer;
			for(int k : w)
				cout<<k<<",";
			cout<<" : "<<i<<", "<<max<<endl;
		}
	}
	return max;
}
int main(){
	cout<<solution({0,1,0,0,1,0,0,1,1,1,1,1,0,0,0,1,0,1,0,1,0,1,0,1,1,1},25);
	return 0;

}
