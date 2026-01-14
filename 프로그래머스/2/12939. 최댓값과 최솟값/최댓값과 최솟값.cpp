#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    int maxi = INT_MIN, mini = INT_MAX;
    stringstream ss(s);
    string n = "";
    while(ss >> n)
    {
        const int nint = stoi(n);
        maxi = max(maxi,nint);
        mini = min(mini,nint);
    }    
    return to_string(mini)+" "+to_string(maxi);
}