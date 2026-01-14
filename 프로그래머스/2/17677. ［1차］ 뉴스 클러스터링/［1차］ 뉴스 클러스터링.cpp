#include <string>
#include <vector>
#include <map>

using namespace std;

inline void toLower(string& str)
{
    for(auto& c : str)
        if('A' <= c && c <= 'Z')
            c += 'a'-'A';
}

int solution(string str1, string str2) {
    toLower(str1);
    toLower(str2);
    
    map<string,pair<int,int>> elem_count;
    for(int i = 0 ; i < str1.size()-1 ; ++i)
        if('a' <= str1[i] && str1[i] <= 'z' && 'a' <= str1[i+1] && str1[i+1] <= 'z')
            ++elem_count[str1.substr(i,2)].first;
    for(int i = 0 ; i < str2.size()-1 ; ++i)
        if('a' <= str2[i] && str2[i] <= 'z' && 'a' <= str2[i+1] && str2[i+1] <= 'z')
            ++elem_count[str2.substr(i,2)].second;

    int intersection = 0, unions = 0;
    for(const auto& e : elem_count)
    {
        intersection += min(e.second.first,e.second.second);
        unions += max(e.second.first,e.second.second);
    }
    if(unions == 0)
        return 65536;
    return intersection/(unions+0.0)*65536;
}