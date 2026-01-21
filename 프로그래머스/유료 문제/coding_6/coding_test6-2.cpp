#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int find_blank(string str, int pos)
{
	for(int i = pos ; i < str.size() ; ++i)
		if(str[i] == ' ')
			return i;
	return str.size();
}
void find_link(vector<string>& all_article, string& article, map<string, string>& link, map<string, bool>& checked)
{
	int p = -1;
	while(1)
	{			
		int b = find_blank(article,p+1);
		string str = article.substr(p+1,b-1-p);
		p = b;
		if(!checked[str])
		{
			all_article.push_back(str);
			checked[str] = true;
			if(link[str] != "")
				find_link(all_article, link[str], link, checked);
		}
		if(p >= article.size())
			return;
	}	
}
vector<int> solution(vector<string> category, vector<string> relation, vector<string> member, vector<string> article) {
	vector<int> answer;
	
	map<string, string> link;
	for(string& s : relation)
	{
		int p = find_blank(s,0);
		link[s.substr(p+1)] = s.substr(0,p);
	}
		
	for(int i = 0 ; i < article.size() ; ++i)
	{	
		vector<string> all_article;
		map<string, bool> checked;
		find_link(all_article, article[i], link, checked);
		int people = 0;
		for(string& m : member)
			for(string& s : all_article)
			{
				if(m.find(s) != std::string::npos)
				{
					++people;
					break;
				}
			}
		answer.push_back(people);
	}
	
	return answer;
}
int main()
{
	for(int i : solution({"culture", "music", "movie", "pop", "jazz", "economy", "technology", "health", "ai"},{"culture music", "culture movie", "music pop", "music jazz", "technology health", "technology ai"},{"Covy culture economy", "Teo music pop jazz", "Felix health ai pop jazz"},{"economy", "pop", "ai technology movie"}))
	{
		printf("%d,",i);
	}
	return 0;
}
