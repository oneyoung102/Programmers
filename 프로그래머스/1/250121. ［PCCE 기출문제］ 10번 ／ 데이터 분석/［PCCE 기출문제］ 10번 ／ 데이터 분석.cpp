#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> first_remodeled_data;
    vector<int> first_remodeled_data_sign(data.size(), 0);
    vector<vector<int>> second_remodeled_data;
    int num;
    if(ext == "code")
        num = 0;
    else if(ext == "date")
        num = 1;
    else if(ext == "maximum")
        num = 2;
    else if(ext == "remain")
        num = 3;
    for(int i = 0 ; i < data.size() ; i++)
    {
        if(data[i][num]<val_ext)
            first_remodeled_data.push_back(data[i]);
    }
    int num1;
    if(sort_by == "code")
        num1 = 0;
    else if(sort_by == "date")
        num1 = 1;
    else if(sort_by == "maximum")
        num1 = 2;
    else if(sort_by == "remain")
        num1 = 3;
    for(int j = 0 ; j < first_remodeled_data.size() ; j++)
    {
        int gap = 29991231;
        int minigap_num;
        for(int i = 0 ; i < first_remodeled_data.size() ; i++)
        {
            if(gap>first_remodeled_data[i][num1]&&first_remodeled_data_sign[i]==0)
            {
                gap = first_remodeled_data[i][num1];
                minigap_num = i;
            }
        }
        first_remodeled_data_sign[minigap_num] = 1;
        second_remodeled_data.push_back(first_remodeled_data[minigap_num]);   
    }
    return second_remodeled_data;
}