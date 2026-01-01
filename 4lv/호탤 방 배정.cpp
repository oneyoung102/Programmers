//2025-11-13 12:31:33
//https://school.programmers.co.kr/learn/courses/30/lessons/64063

#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
using llong = long long;

vector<llong> solution(llong k, vector<llong> room_number) {
    vector<llong> answer;
    unordered_map<llong,llong> room_link;
    for(const llong n : room_number)
    {
        llong linked_room = n;
        while(room_link[linked_room] != 0ll)
            linked_room = room_link[linked_room];
        answer.push_back(linked_room);
        llong room = n;
        while(room_link[room] != 0ll)
            room = exchange(room_link[room],linked_room+1);
        room_link[room] = linked_room+1;
    }
    return answer;
}
