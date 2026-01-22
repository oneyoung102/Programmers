#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer(query.size(),0);
 
    map<string,int> number;
    const int query_types[4] = {3,2,2,2};
    number["cpp"] = 0;
    number["backend"] = 0;
    number["junior"] = 0;
    number["chicken"] = 0;
    number["java"] = 1;
    number["frontend"] = 1;
    number["senior"] = 1;
    number["pizza"] = 1;
    number["python"] = 2;
    
    vector<int> info_array[query_types[0]][query_types[1]][query_types[2]][query_types[3]];
    for(int i = 0 ; i < info.size() ; ++i)
    {
        vector<int> identity;
        string s;
        for(const char c : info[i])
        {
            if(c == ' ')
            {
                identity.push_back(number[s]);
                s = "";
            }
            else
                s.push_back(c);
        }
        identity.push_back(stoi(s));
        info_array[identity[0]][identity[1]][identity[2]][identity[3]].push_back(identity[4]);
    }
    for(int a = 0 ; a < query_types[0] ; a++)
        for(int b = 0 ; b < query_types[1] ; b++)
            for(int c = 0 ; c < query_types[2] ; c++)
                for(int d = 0 ; d < query_types[3] ; d++)
                    sort(info_array[a][b][c][d].begin(), info_array[a][b][c][d].end());
    for(int i = 0 ; i < query.size() ; ++i)
    {
        vector<vector<int>> squery(5);
        string s;
        int n = 0;
        for(int j = 0 ; j < query[i].size() ; ++j)
            if(query[i][j] == ' ')
            {
                if(s == "-")
                    for(int k = 0 ; k < query_types[n] ; ++k)
                        squery[n].push_back(k);
                else
                    squery[n].push_back(number[s]);
                if(query[i][j+1] == 'a')
                    j += 4;
                s = "";        
                ++n;
            }
            else
                s.push_back(query[i][j]);
        squery[n].push_back(stoi(s));
        
        for(const int a : squery[0])
            for(const int b : squery[1])
                for(const int c : squery[2])
                    for(const int d : squery[3])
                        answer[i] += info_array[a][b][c][d].end() - lower_bound(info_array[a][b][c][d].begin(),info_array[a][b][c][d].end(),squery[4][0]);
    }
    return answer;
}