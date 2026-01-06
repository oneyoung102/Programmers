#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long find_year(string str){return stoi(str.substr(0,4));}
long find_month(string str){return stoi(str.substr(5,2));}
long find_day(string str){return stoi(str.substr(8,2));}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char, int> type;
    
    for(int i = 0 ; i < terms.size() ; i++)
        type[terms[i][0]] = i;
    for(int i = 0 ; i < privacies.size() ; i++)
        if(28*12*(find_year(today)-find_year(privacies[i])-stoi(terms[type[privacies[i][11]]].substr(2))/12)+28*(find_month(today)-find_month(privacies[i])-stoi(terms[type[privacies[i][11]]].substr(2))%12)+find_day(today)-find_day(privacies[i])>=0)
            answer.push_back(i+1);     
    return answer;
}