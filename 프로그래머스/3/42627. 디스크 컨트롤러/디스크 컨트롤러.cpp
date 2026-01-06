#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct disk_controll
{
    disk_controll(){};
    bool operator()(vector<int>& a, vector<int>& b)
    {
        if(a[1] == b[1])
            return a[0] > b[0];
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(),jobs.end(),[](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });
    priority_queue<vector<int>,vector<vector<int>>,disk_controll> dc;
    int time = 0, i = 0, gap_sum = 0;
    while (i < jobs.size() || !dc.empty()) {
        while (i < jobs.size() && jobs[i][0] <= time)
            dc.push(jobs[i++]);

        if (dc.empty()) {
            time = jobs[i][0];
            continue;
        }

        auto job = dc.top(); dc.pop();
        time += job[1];
        gap_sum += time - job[0];
    }
    return gap_sum/jobs.size();
}