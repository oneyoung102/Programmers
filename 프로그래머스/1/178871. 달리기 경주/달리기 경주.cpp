#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int>  players_pos;
    for(int i = 0 ; i < players.size() ; i++)
        players_pos[players[i]] = i;
    for(auto& it : callings)
    {
        swap(players[players_pos[it]], players[players_pos[it]-1]);
        players_pos[it]--;
        players_pos[players[players_pos[it]+1]]++;
    }
    return players;
}