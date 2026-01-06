#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GetPlusNumber(string a, string b, unsigned int base)
{
    string number = "";
    int n = 0, ap = a.size()-1, bp = b.size()-1;
    while(ap != -1 || bp != -1)
    {
        if(ap != -1)
            n += a[ap--]-'0';
        if(bp != -1)
            n += b[bp--]-'0';
        if(n < base)
        {
            number += n+'0';
            n = 0;
        }
        else
        {
            number += n-base+'0';
            n = 1;
        }
    }
    if(n == 1)
        number += '1';
    reverse(number.begin(),number.end());
    return stoi(number);
}
int GetMinusNumber(string a, string b, unsigned int base)
{//항상 a > b
    string number = "";
    int n = 0, ap = a.size()-1, bp = b.size()-1;
    while(ap != -1 || bp != -1)
    {
        if(ap != -1)
            n += a[ap--]-'0';
        if(bp != -1)
            n -= b[bp--]-'0';
        if(n >= 0)
        {
            number += n+'0';
            n = 0;
        }
        else
        {
            number += n+base+'0';
            n = -1;
        }
    }
    reverse(number.begin(),number.end());
    return stoi(number);
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    int left = 2, right = 9;
    for(string& s :  expressions)
    {
        char operate_t;
        bool x_find = false;
        int operate_p = 0, equal_p = 0;
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(s[i] == 'X')
            {
                answer.push_back(s);
                x_find = true;
            }
            else
            {
                if(s[i]-'0' > 0 && s[i]-'0' < 10)
                {
                    if(left != right &&  s[i]-'0' >= left)
                        left = s[i]-'0'+1;
                }
                else if(s[i] == '+' || s[i] == '-')
                {
                    operate_p = i; 
                    operate_t = s[i];
                }
                else if(s[i] == '=')
                    equal_p = i; 
            }
        }
        if(left != right && !x_find)
        {
            int ten_base_num, gap;
            if(operate_t == '+')
            {
                ten_base_num = stoi(s.substr(0,operate_p-1))+stoi(s.substr(operate_p+2,equal_p-operate_p-3));
                gap = stoi(s.substr(equal_p+2))-ten_base_num;
            }
            else
            {
                ten_base_num = stoi(s.substr(0,operate_p-1))-stoi(s.substr(operate_p+2,equal_p-operate_p-3));
                gap = ten_base_num - stoi(s.substr(equal_p+2));
            }
            if(gap != 0)
            {
                right = 10-to_string(gap).front()+'0';
                left = right;
            }
        }
    }
    for(string& s :  answer)
    {
        char operate_t;
        int operate_p = 0, equal_p = 0;
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(s[i] == '+' || s[i] == '-')
            {
                operate_t = s[i];
                operate_p = i;
            }
            else if(s[i] == '=')
            {
                equal_p = i;
                break;
            }
        }
        string first = s.substr(0,operate_p-1),
        second = s.substr(operate_p+2,equal_p-operate_p-3),
        last = s.substr(equal_p+2); 
        int result_l = 0, result_r = 0;
        if(first == "X")
        {
            if(operate_t == '+')
            {
                result_l = GetMinusNumber(last,second,left);
                if(left != right)
                    result_r = GetMinusNumber(last,second,right);
                else
                    result_r = result_l;
            }
            else
            {
                result_l = GetPlusNumber(last,second,left);
                if(left != right)
                    result_r = GetPlusNumber(last,second,right);
                else
                    result_r = result_l;
            }
            if(result_r == result_l)
                first = to_string(result_l);
            else
                first = "?";
        }
        else if(second == "X")
        {
            if(operate_t == '+')
            {
                result_l = GetMinusNumber(last,first,left);
                if(left != right)
                    result_r = GetMinusNumber(last,first,right);
                else
                    result_r = result_l;
            }
            else
            {
                result_l = GetMinusNumber(first,last,left);
                if(left != right)
                    result_r = GetMinusNumber(first,last,right);
                else
                    result_r = result_l;
            }
            if(result_r == result_l)
                second = to_string(result_l);
            else
                second = "?";
        }
        else
        {
            if(operate_t == '+')
            {
                result_l = GetPlusNumber(first,second,left);
                if(left != right)
                    result_r = GetPlusNumber(first,second,right);
                else
                    result_r = result_l;
            }
            else
            {
                result_l = GetMinusNumber(first,second,left);
                if(left != right)
                    result_r = GetMinusNumber(first,second,right);
                else
                    result_r = result_l;
            }
            if(result_r == result_l)
                last = to_string(result_l);
            else
                last = "?";
        }
        s = first+' '+operate_t+' '+second+" = "+last;
    }
    return answer;
}