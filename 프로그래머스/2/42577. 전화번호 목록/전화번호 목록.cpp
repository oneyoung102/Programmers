#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(),phone_book.end(),[](string& x, string& y){
        return x.size() > y.size();
    });
    map<string,bool> mf;
    for(const string& s : phone_book)
    {
        string temp = "";
        for(int i = 0 ; i < s.size()-1 ; ++i)
        {
            temp += s[i];
            mf[temp] = true;
        }
        if(mf[s]) return false;
        else mf[s] = true;
    }
    return true;
}