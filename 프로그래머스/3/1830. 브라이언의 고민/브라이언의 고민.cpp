#include <vector>
#include <string>

using namespace std;

inline bool is_spc(char c){return c >= 'a' && c <= 'z';};
inline bool is_blank(char c){return c == ' ';};

string inside_rule(string& sentence, int begin, vector<bool>& seen_spc)
{
    string str = "";
    char spc = 0;
    int i = begin;
    while(true)
    {
        if((i-begin)%2 == 0)
        {
            if(i == sentence.size())
                return "invalid"; 
            if(is_spc(sentence[i]) || is_blank(sentence[i]))
                return "invalid";          
            else
                str += sentence[i];            
        }
        else
        {
            if(i == sentence.size())
                break; 
            if(spc == 0 && is_spc(sentence[i]))
            {
                spc = sentence[i];
                if(seen_spc[spc-'a'])
                    return "invalid";
            }
            else if(spc != sentence[i])
                break;
        }
        ++i;
    }
    seen_spc[spc-'a'] = true;
    return str;
}
string outside_rule(string& sentence, int begin, vector<bool>& seen_spc)
{
    string str = "";
    char spc = sentence[begin];
    if(seen_spc[spc-'a'])
        return "invalid";

    int i = begin+1;
    while(sentence[i] != spc)
    {
        if(i == sentence.size())
            return "invalid"; 
        if(is_spc(sentence[i]) || is_blank(sentence[i]))
            return "invalid"; 
        else
            str += sentence[i];
        ++i; 
    }
    seen_spc[spc-'a'] = true;
    return str;
}
string inoutside_rule(string& sentence, int begin, vector<bool>& seen_spc)
{
    string str = "";
    char spc_out = sentence[begin], spc_in = 0;
    if(seen_spc[spc_out-'a'])
        return "invalid";

    int i = begin+1;
    while(sentence[i] != spc_out)
    {
        if(i == sentence.size())
            return "invalid"; 
        if((i-begin)%2 == 1)
        {
            if(is_spc(sentence[i]) || is_blank(sentence[i]))
                return "invalid";
            else
                str += sentence[i];
        }
        else
        {
            if(spc_in == 0 && is_spc(sentence[i]))
            {
                spc_in = sentence[i];
                if(seen_spc[spc_in-'a'])
                    return "invalid";
            }
            else if(spc_in != sentence[i])
                return "invalid";
        }
        ++i;
    }
    seen_spc[spc_out-'a'] = true;
    seen_spc[spc_in-'a'] = true;
    return str;
}

string solution(string sentence) {
    string sub_answer = "";

    vector<bool> seen_spc('z'-'a'+1,false);// 소문자(특수문자) 중복 확인
    int i = 0; 
    while(i < sentence.size())
    {
        if(is_spc(sentence[i])) //첫 시작 문자가 소문자(특수문자)일 때
        {
            if(i < sentence.size()-1)
            {
                if(is_spc(sentence[i+1]))
                    return "invalid";
                else
                {
                    if(i < sentence.size()-2)
                    {
                        if(is_spc(sentence[i+2]))
                        {
                            if(sentence[i] != sentence[i+2])// aBbBbBbBa
                            {
                                string str = inoutside_rule(sentence,i,seen_spc);
                                if(str == "invalid")
                                    return "invalid";
                                i += str.size()*2+1;
                                sub_answer += ' '+str+' ';
                            }
                            else// aAa
                            {
                                string str = outside_rule(sentence,i,seen_spc);
                                if(str == "invalid")
                                    return "invalid";
                                i += str.size()+2;
                                sub_answer += ' '+str+' ';
                            }
                        }
                        else// aAAAAAAa
                        {
                            string str = outside_rule(sentence,i,seen_spc);
                            if(str == "invalid")
                                return "invalid";
                            i += str.size()+2;
                            sub_answer += ' '+str+' ';
                        }
                    }
                    else
                        return "invalid";
                }
            }
            else
                return "invalid";
        }
        else
        {
            if(i < sentence.size()-1)
            {
                if(is_spc(sentence[i+1])) // BbBbB
                {
                    int count = 0, pos = -1;
                    for(int j = i+2; j < sentence.size() ; ++j)
                        if(sentence[j] == sentence[i+1])
                        {
                            if(pos == -1)
                                pos = j;
                            ++count;
                        }
                    if(pos-i == 2)
                        return "invalid";
                    else if(pos-i == 3 || pos == -1)
                    {
                        if(count == 1)
                        {
                            sub_answer += sentence[i];
                            ++i;
                        }
                        else
                        {
                            string str = inside_rule(sentence,i,seen_spc);
                            if(str == "invalid")
                                return "invalid";
                            i += str.size()*2-1;
                            sub_answer += ' '+str+' ';
                        }
                    }
                    else
                    {
                        sub_answer += sentence[i];
                        ++i;
                    }
                }
                else // AA
                {
                    sub_answer += sentence[i];
                    ++i;
                }
            }
            else // A
            {
                sub_answer += sentence[i];
                ++i;
            }
        }
    }
    string answer = "";
    for(int i = 0 ; i < sub_answer.size() ; ++i)
    {
        if(is_blank(sub_answer[i]))
        {
            if(i != 0 && i != sub_answer.size()-1 && !is_blank(answer.back()))
                answer += sub_answer[i];
        }
        else
            answer += sub_answer[i];
    }
    return answer;
}