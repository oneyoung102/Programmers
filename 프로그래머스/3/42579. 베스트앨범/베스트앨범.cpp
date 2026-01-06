#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

using hp = pair<int,int>; //hash & play
using np = pair<string,int>; //name & total play

template<class T>
struct play_sort
{
    bool operator()(T& p1, T& p2){return p1.second < p2.second;}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,priority_queue<hp,vector<hp>,play_sort<hp>>> hp_map;
    map<string,int> play_count;
    for(size_t i = 0 ; i < genres.size() ; ++i)
    {
        const string song_name = genres[i];
        hp_map[song_name].push(make_pair(i,plays[i]));
        play_count[song_name] += plays[i];
    }
    priority_queue<np,vector<np>,play_sort<np>> play_count_sorted;
    for(const np& p : play_count)
        play_count_sorted.push(p);
    while(!play_count_sorted.empty())
    {
        const string song_name = play_count_sorted.top().first;
        auto& hppq = hp_map[song_name];
        play_count_sorted.pop();
        answer.push_back(hppq.top().first);
        hppq.pop();
        if(!hppq.empty())
            answer.push_back(hppq.top().first);    
    }
    return answer;
}