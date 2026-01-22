#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int total_weight = 0, truck_index = 0;
    vector<int> trucks;
    while(truck_index < truck_weights.size())
    {
        const int tw = truck_weights[truck_index];
        if(total_weight + tw <= weight)
        {
            total_weight += tw;
            trucks.push_back(tw);
            ++truck_index;
        }
        else
            trucks.push_back(0);
        if(trucks.size() >= bridge_length)
            total_weight -= trucks[trucks.size()-bridge_length];
    }
    return trucks.size()+bridge_length;
}