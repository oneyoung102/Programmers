#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    for(int i = 0 ; i < answer.size() ; i++)
    {
        if(answer[i] >= 'A' && answer[i]<='Z')
            answer[i] += 32;
        else if((answer[i] < '0' || answer[i]>'9')&&(answer[i] < 'a' || answer[i]>'z')&&answer[i] != '-' && answer[i] != '_' & answer[i] != '.')
        {
            answer.erase(answer.begin()+i);
            i-=1;
        }     
    }
    for(int i = 0 ; i < answer.size() ; i++)
    {
        if(answer[i] == '.')
            if(i == 0 || i == answer.size()-1 || answer[i+1] == '.')
            {
                 answer.erase(answer.begin()+i);
                i-=1;
            } 
    }
    
    if(answer.size()>15)
    {
        answer.erase(15);
        if(answer[answer.size()-1]=='.')
            answer.erase(answer.begin()+14);
    }
    else if(answer.size()<3)
    {
        if(answer.size()==0)
            answer="a";
        while(answer.size()<3)
            answer.push_back(answer[answer.size()-1]);
    }
       
        
    
    
    return answer;
}