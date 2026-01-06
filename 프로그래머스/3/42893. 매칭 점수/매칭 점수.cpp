#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cctype>

using namespace std;

unordered_map<string,int> numbering;

string lower(string s){
    for(char& c : s)
        c = tolower(c);
    return s;
}

bool isAlphabet(char c){return 'A' <= c && c <= 'Z' || 'a' <= c && c <= 'z';}

string get_url(const string& html, const string start, const char finish)
{
    for(int i = 0 ; i < html.size()-start.size() ; ++i)
        if(html[i] == start[0] && html.substr(i,start.size()) == start)
            for(int j = i+start.size() ; j < html.size()-start.size() ; ++j)
                if(html[j] == finish)
                    return html.substr(i+start.size(),j-i-start.size());
    return "none";
}

vector<int> get_ll(const string& html, const string start, const char finish)
{
    vector<int> ll;
    ll.push_back(0);
    for(int i = 0 ; i < html.size()-start.size() ; ++i)
        if(html[i] == start[0] && html.substr(i,start.size()) == start)
            for(int j = i+start.size() ; j < html.size()-start.size() ; ++j)
                if(html[j] == finish)
                {
                    ++ll[0];
                    const int linked_url = numbering[html.substr(i+start.size(),j-i-start.size())];
                    if(linked_url != 0)
                        ll.push_back(linked_url-1);
                    break;
                }
    return ll;
}

int get_basic(const string& html, const string& word)
{
    int score = 0;
    for(int i = 0 ; i < html.size()-word.size()+1 ; ++i)
        if(word[0] == tolower(html[i]) && (i == 0 || !isAlphabet(html[i-1])))   
            if(lower(html.substr(i,word.size())) == word && (i+word.size() == html.size() || !isAlphabet(html[i+word.size()])))
                ++score;
    return score;
}

int solution(string word, vector<string> pages) {
    vector<int> basic;
    vector<int> linking;
    vector<unordered_set<int>> linked;

    word = lower(word);

    for(int i = 0 ; i < pages.size() ; ++i)
    {
        const string url = get_url(pages[i],"<meta property=\"og:url\" content=\"",'\"');
        numbering[url] = i+1;
        basic.push_back(0);
        linking.push_back(0);
        linked.push_back(unordered_set<int>());
    }
    for(int i = 0 ; i < pages.size() ; ++i)
    {
        vector<int> ll = get_ll(pages[i],"<a href=\"",'\"');
        linking[i] = ll[0];
        for(int j = 1 ; j < ll.size() ; ++j)
            linked[ll[j]].insert(i);
        basic[i] = get_basic(pages[i],word);
    }

    int cdd = 1;
    printf("%d,%d,%zu\n",basic[cdd],linking[cdd],linked[cdd].size());

    int answer = -1;
    double max_final_score = -1;
    for(int i = 0 ; i < pages.size() ; ++i)
    {
        double final_score = basic[i];
        const auto& s = linked[i];
        for(auto it = s.begin() ; it != s.end() ; ++it)
            if(linking[*it] != 0)
                final_score += (double)basic[*it]/linking[*it];
        if(final_score > max_final_score)
        {
            max_final_score = final_score;
            answer = i;
        }
    }
    return answer;
}