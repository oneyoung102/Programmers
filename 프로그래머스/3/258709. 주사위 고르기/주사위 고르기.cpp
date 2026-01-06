#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;
class calculate_cases {
    private :
        int dice_amount, candidate_max, selected_sum;;
        vector<vector<int>> dice;
        vector<int> selected, sub_selected;
        map<vector<int>,bool> dice_comb_seen;
        
        void sum_combination(int amount, int sum, vector<int>& select, multiset<int>& combs)
        {//주사위 눈 합 조합 구하기
            if(amount != dice_amount/2)
            {
                for(int j = 0 ; j < 6 ; ++j)
                    sum_combination(amount+1,sum+dice[select[amount]-1][j],select,combs);
            }
            else
                combs.insert(sum);
            return;
        }  
        vector<int> whichwin(multiset<int>& c1, multiset<int>& c2)
        {
            int win = 0, total_win = 0, tie = 0;
            auto next_begin = c2.begin();
            for (auto it1 = c1.begin(); it1 != c1.end(); ++it1)
            {
                total_win += distance(next_begin, c2.lower_bound(*it1));
                win += total_win;
                tie += distance(c2.lower_bound(*it1), c2.upper_bound(*it1));
                next_begin = c2.lower_bound(*it1);
            }
            
            const int total = (int)c1.size() * (int)c2.size();
            const int oppose_win = total - win - tie;
            
            if (oppose_win < win)
                return {0, win};
            else
                return {1, oppose_win};
        }
    
    public :
        calculate_cases(vector<vector<int>>& d)
        : dice(d)
        {
            dice_amount = d.size();
            candidate_max = 0;
            selected_sum = 0;
            for(int i = 0 ; i < dice_amount/2 ; ++i)
                sub_selected.push_back(-1);
        }
        ~calculate_cases(){}
    
        vector<int> select_dice(int amount, int pos)
        {
            if(amount != dice_amount/2)
            {
                for(int i = pos ; i < dice_amount/2 + amount + 1 ; ++i)//주사위 선택 조합 구하기
                {
                    sub_selected[amount] = i+1;
                    select_dice(amount+1,i+1); 
                }
            }
            else if(!dice_comb_seen[sub_selected])
            {
                multiset<int> combs1; //첫 번째 주사위 눈 합 조합
                sum_combination(0,0,sub_selected,combs1);
                dice_comb_seen[sub_selected] = true;

                multiset<int> combs2;//두 번째 주사위 눈 합 조합
                vector<int> oppose_sub_selected;
                int p = 0;//첫 번째 주사위 조합 반대의 조합 구하기
                for(int i = 1 ; i <= dice_amount ; ++i)
                    if(p == dice_amount/2 || sub_selected[p] != i)
                        oppose_sub_selected.push_back(i);
                    else
                        ++p;
                sum_combination(0,0,oppose_sub_selected,combs2);
                dice_comb_seen[oppose_sub_selected] = true;

                const vector<int> candidate = whichwin(combs1,combs2);//두 조합 중 이긴 횟수가 많은 조합구하기
                if(candidate[1] > candidate_max)
                {
                    candidate_max = candidate[1];
                    if(candidate[0] == 0)
                        selected = sub_selected;
                    else
                        selected = oppose_sub_selected;
                }
            }  
            return selected;  
        }
};

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    calculate_cases CLCC(dice);
    answer = CLCC.select_dice(0,0);
    return answer;
} 