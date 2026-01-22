#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct song
{
    int time;
    string name;
    string melody;
};

string convert_melody(const string& m)
{
    string mc = "";
    int i = 0;
    while(i < m.size()-1)
        if(m[i+1] == '#')
        {
            mc += m[i]-'a';
            i += 2;
        }
        else
            mc += m[i++];
    if(i == m.size()-1)
        mc += m[i];
    return mc;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    m = convert_melody(m);
    int answer_time = 0;
    vector<song> songs;
    for(const auto& s : musicinfos)
    {
        const int start = 60*stoi(s.substr(0,2))+stoi(s.substr(3,2));
        const int end = 60*stoi(s.substr(6,2))+stoi(s.substr(9,2));
        const int comma = distance(s.begin(),find(s.begin()+13,s.end(),','));
        songs.push_back(song{end-start,s.substr(12,comma-12),convert_melody(s.substr(comma+1))});
    }
    for(const auto& ss : songs)
    {
        for(int i = 0 ; i < ss.melody.size() ; ++i)
        {
            bool same = true;
            for(int j = 0 ; j < m.size() ; ++j)
                if(j+i >= ss.time || m[j] != ss.melody[(j+i)%ss.melody.size()])
                {
                    same = false;
                    break;
                }
            if(same && answer_time < ss.time)
            {
                answer = ss.name;
                answer_time = ss.time;
            }
        }
    }
    return answer;
}