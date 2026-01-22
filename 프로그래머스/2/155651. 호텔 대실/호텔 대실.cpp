#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<vector<string>> book_time) {
    auto ttoi = [](string s) -> int {
        return stoi(s.substr(0,2))*60+stoi(s.substr(3,2));
    };
    
    sort(book_time.begin(),book_time.end(),[ttoi](vector<string>& a, vector<string>& b) -> bool {
        const int A = ttoi(a[0]), B = ttoi(b[0]);
        if(A < B)
            return true;    
        else if(A == B)
            return ttoi(a[1]) < ttoi(b[1]);
        return false;
    });
    
    vector<vector<int>> rooms;
    for(vector<string>& it : book_time)
    {
        if(rooms.empty())
            rooms.push_back({ttoi(it[1])+10});
        else
        {
            int best_pos = -1, min_gap = 1440;
            for(int i = 0 ; i < rooms.size() ; ++i)
            {
                const int gap = ttoi(it[0])-rooms[i].back();
                if(gap == 0)
                {
                    best_pos = i;
                    break;
                }
                else if(gap > 0 && min_gap > gap)
                {
                    min_gap = gap;
                    best_pos = i;
                }
            }
            if(best_pos >= 0)
                rooms[best_pos].push_back(ttoi(it[1])+10);
            else
                rooms.push_back({ttoi(it[1])+10});
        }       
    } 
    return rooms.size();
}