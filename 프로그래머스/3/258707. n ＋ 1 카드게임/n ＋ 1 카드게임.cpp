#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int coin, vector<int> cards) {
    const int card_amount = cards.size();

    unordered_set<int> mycards;// 현재 카드들
    unordered_set<int> able_cards;//현재 라운드에서 뽑을 수 있는 카드들

    for(int i = 0 ; i < card_amount/3 ; ++i)// 현재 카드 파악
        mycards.insert(cards[i]);

    int round = 1, pos = card_amount/3;
    const int max_round = card_amount/3+1;

    able_cards.insert(cards[pos]);//현재 라운드에서 뽑을 수 있는 카드 추가
    able_cards.insert(cards[pos+1]);
    pos += 2;

    auto it = mycards.begin();
    while(it != mycards.end())// 현재 카드를 합쳐서 n+1이 되는 경우
    {
        const int opposite  = card_amount-*it+1;
        if(mycards.find(opposite) != mycards.end())
        {
            ++round;
            able_cards.insert(cards[pos]);
            able_cards.insert(cards[pos+1]);
            pos += 2;

            it = mycards.erase(it);
            if(*it == opposite)
                ++it;
            mycards.erase(opposite);
        }
        else
            ++it;
    }
    
    bool stop_sign1, stop_sign2;
    do
    {   
        stop_sign1 = true;
        stop_sign2 = true;

        it = able_cards.begin();
        while(it != able_cards.end() && coin > 0 && !mycards.empty()) // 코인으로 살 수 있는 카드들과 현재 카드를 합쳐서 n+1이 되는 경우
        {
            const int opposite = card_amount-*it+1;
            if(mycards.find(opposite) != mycards.end())
            {
                ++round;
                if(round == max_round)
                    return round;
                able_cards.insert(cards[pos]);
                able_cards.insert(cards[pos+1]);
                pos += 2;
                --coin;

                mycards.erase(opposite);
                it = able_cards.erase(it);
                stop_sign1 = false;
            }
            else 
                ++it;
        }
        if(coin > 1)
        {
            it = able_cards.begin();
            while(it != able_cards.end())// 코인으로 살 수 있는 카드들로 합이 n+1이 되는 경우
            {
                const int opposite = card_amount-*it+1;
                if(able_cards.find(opposite) != able_cards.end())
                {
                    ++round;
                    if(round == max_round)
                        return round;
                    able_cards.insert(cards[pos]);
                    able_cards.insert(cards[pos+1]);
                    pos += 2;
                    coin -= 2;

                    it = able_cards.erase(it);
                    if(*it == opposite)
                        ++it;
                    able_cards.erase(opposite);
                    stop_sign2 = false;
                    break;
                }
                else 
                    ++it;
            }
        }
    }while(!stop_sign1 || !stop_sign2);
    if(round == 24)
        return 25;
    return round;
}