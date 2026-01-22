#include <string>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

int take_a_photo(unordered_set<char>& friends, unordered_set<string>& conditions, vector<char>& photo)
{
    if(conditions.empty())
        return 1;
    const string c = *(conditions.begin());
    conditions.erase(conditions.begin());
    int cases = 0;
    int start_f = 0, finish_f = photo.size(), start_s = 0, finish_s = photo.size();
    char compare_f = '?', compare_s = '?';
    function<bool(int)>* compare_with;
    function<bool(int)> equal = [c](int n) -> bool{return n == c[4]-'0'+1;};
    function<bool(int)> big = [c](int n) -> bool{return n > c[4]-'0'+1;};
    function<bool(int)> small = [c](int n) -> bool{return n < c[4]-'0'+1;};
    if(c[3] == '=')
        compare_with = &equal;
    else if(c[3] == '>')
        compare_with = &big;
    else    
        compare_with = &small;
    if(friends.find(c[0]) == friends.end())
    {
        for(int i = 0 ; i < photo.size() ; ++i)
            if(photo[i] == c[0])
            {
                start_f = i;
                finish_f = i+1;
                break;
            }
        compare_f = c[0];
    }
    if(friends.find(c[2]) == friends.end())
    {
        for(int i = 0 ; i < photo.size() ; ++i)
            if(photo[i] == c[2])
            {
                start_s = i;
                finish_s = i+1;
                break;
            }
        compare_s = c[2];
    }
    for(int i = start_f ; i < finish_f ; ++i)
    {
        if(photo[i] == compare_f)
        {
            if(compare_f == '?')
            {
                friends.erase(c[0]);
                photo[i] = c[0]; 
            }
            for(int j = start_s; j < finish_s; ++j)
                if(i < j && (*compare_with)(j-i) || i > j && (*compare_with)(i-j))
                {
                    if(photo[j] == compare_s)
                    {
                        if(compare_s == '?')
                        {
                            friends.erase(c[2]);
                            photo[j] = c[2];
                        }
                        cases += take_a_photo(friends,conditions,photo);
                        if(compare_s == '?')
                        {
                            friends.insert(c[2]);
                            photo[j] = '?';
                        }
                    }
                }
            if(compare_f == '?')
            {
                friends.insert(c[0]);
                photo[i] = '?';
            }
        }
    }
    conditions.insert(c);//conditions.begin(),
    return cases;
}
int solution(int n, vector<string> data) {
    int answer = 1;
    unordered_set<char> friends;   
    unordered_set<string> conditions;
    for(string& d : data)
    {
        friends.insert(d[0]);
        friends.insert(d[2]);
        conditions.insert(d);
    }
    for(int i = 2 ; i <= 8-friends.size() ; ++i) //남은 친구 배치 조합
        answer *= i;
    vector<char> photo(8,'?');
    answer *= take_a_photo(friends,conditions,photo);
    return answer;
}