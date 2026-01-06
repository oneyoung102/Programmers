#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<string>> graph(50,vector<string>(50,"EMPTY"));
int merge_code = 0;
vector<string> merged_shell;

bool is_code(string& s){return s[0] == '#';}

string& get_value(string& s)
{
    if(is_code(s))
        return merged_shell[stoi(s.substr(1))];
    return s;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(const string& command : commands)
    {
        stringstream ss(command);
        string name,v1,v2,v3,v4;
        ss >> name >> v1 >> v2 >> v3 >> v4;
        if(name == "UPDATE")
        { 
            if(v3 == "")
            {
                for(auto& row : graph)
                    for(string& cell : row)
                    {
                        string& value = get_value(cell);
                        if(value == v1)
                            value = v2;
                    }
            }
            else
            {
                const int r = stoi(v1)-1, c = stoi(v2)-1;
                get_value(graph[r][c]) = v3;
            }
        }
        else if(name == "MERGE")
        {
            int r1 = stoi(v1)-1, c1 = stoi(v2)-1, r2 = stoi(v3)-1, c2 = stoi(v4)-1;
            if(r1 == r2 && c1 == c2 || is_code(graph[r1][c1]) && is_code(graph[r2][c2]) && graph[r1][c1] == graph[r2][c2])
                continue;
            if(get_value(graph[r1][c1]) == "EMPTY")
            {
                swap(r1,r2);
                swap(c1,c2);
            }
            string code1 = graph[r1][c1];
            if(!is_code(graph[r1][c1]))
            {
                merged_shell.push_back(graph[r1][c1]);
                code1 = "#"+to_string(merge_code++);
                graph[r1][c1] = code1;
            }   
            if(is_code(graph[r2][c2]))
            {
                const string code2 = graph[r2][c2];  
                for(auto& row : graph)
                    for(string& cell : row)
                        if(cell == code2)
                            cell = code1;
            }  
            else
                graph[r2][c2] = code1;
        }
        else if(name == "UNMERGE")
        {
            const int r = stoi(v1)-1, c = stoi(v2)-1;
            if(!is_code(graph[r][c]))
                continue;
            const string code = graph[r][c];
            graph[r][c] = get_value(graph[r][c]);
            for(auto& row : graph)
                for(string& cell : row)
                    if(cell == code)
                        cell = "EMPTY";
        }
        else//PRINT
        {
            const int r = stoi(v1)-1, c = stoi(v2)-1;
            answer.push_back(get_value(graph[r][c]));
        }
    }
    return answer;
}