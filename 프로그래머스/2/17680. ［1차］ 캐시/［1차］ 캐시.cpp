#include <string>
#include <vector>
#include <algorithm>

using namespace std;

inline void toLower(string& s)
{
    for(char& c : s)
        if('A' <= c && c <= 'Z')
            c += 'a'-'A';
}

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0)
        return cities.size()*5;
    int time = 0;
    vector<string> cache;
    for(string& c : cities)
    {
        toLower(c);
        const auto it = find(cache.begin(),cache.end(),c);
        if(it == cache.end())
        {
            if(cache.size() == cacheSize)
                cache.pop_back();
            time += 5;
        }
        else
        {
            cache.erase(it);   
            time += 1;
        }
        cache.insert(cache.begin(),c);
    }
    return time;
}