#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

class file_sort
{
    public :
    bool operator()(const vector<string>& v1, const vector<string>& v2)
    {
        if(v1[0] < v2[0])
            return true;
        if(v1[0] == v2[0])
            return stoi(v1[1]) < stoi(v2[1]);
        return false;
    };
};

class transform_file
{
    private :
        string lower(const string& s1)
        {
            string s2(s1.size(),'\0');
            transform(s1.begin(),s1.end(),s2.begin(),[](const char c){
               return tolower(c); 
            });
            return s2;
        }
        bool is_number(const char c)
        {
            return c >= '0' && c <= '9';
        }
        int first_num_pos(const string& s)
        {
            const auto it = find_if(s.begin(),s.end(),[this](const char c){
               return this->is_number(c); 
            });
            return distance(s.begin(),it);
        }
        int first_char_pos(const string& s)
        {
            const auto it = find_if(s.begin(),s.end(),[this](const char c){
               return !this->is_number(c); 
            });
            return distance(s.begin(),it);
        }
    public :
    
        vector<string> operator()(const string& s)
        {
            const int number_begin = first_num_pos(s);
            const string head = s.substr(0,number_begin), rear = s.substr(number_begin);
            int tail_begin = first_char_pos(rear);
            if(tail_begin > 5)
                tail_begin = 5;
            const string number = rear.substr(0,tail_begin);
            return {lower(head),number,s};
        };
};

vector<string> solution(vector<string> files) {
    vector<vector<string>> file_info(files.size());
    transform(files.begin(),files.end(),file_info.begin(),transform_file());
    stable_sort(file_info.begin(),file_info.end(),file_sort());
    vector<string> sorted_files(files.size());
    transform(file_info.begin(),file_info.end(),sorted_files.begin(),[](const vector<string>& v){
        return v[2];
    });
    return sorted_files;
}