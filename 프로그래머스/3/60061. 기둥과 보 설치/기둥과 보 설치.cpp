#include <vector>

using namespace std; 


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<bool>> pillar(n+1,vector<bool>(n+1,false)), beam(n+1,vector<bool>(n+1,false));
    const auto pillar_test = [n,&pillar,&beam](int x, int y) -> bool{
        return (y == 0 || pillar[y-1][x] || beam[y][x] || x != 0 && beam[y][x-1]);
    };
    const auto beam_test = [n,&pillar,&beam](int x, int y) -> bool{
        return (pillar[y-1][x] || pillar[y-1][x+1] || x != 0 && beam[y][x-1] && beam[y][x+1]);
    };
    for(const auto& frame : build_frame)
    {
        const int x = frame[0], y = frame[1];
        if(frame[2] == 0)//기둥
        {
            if(frame[3] == 0)//삭제
            {
                pillar[y][x] = false;
                if(pillar[y+1][x] && !pillar_test(x,y+1) || x != 0 && beam[y+1][x-1] && !beam_test(x-1,y+1) || beam[y+1][x] && !beam_test(x,y+1))
                    pillar[y][x] = true;
            }
            else//건설
                pillar[y][x] = pillar_test(x,y);
        }
        else//보
        {
            if(frame[3] == 0)//삭제
            {
                beam[y][x] = false;
                if(x != 0 && beam[y][x-1] && !beam_test(x-1,y) || x != n && beam[y][x+1] && !beam_test(x+1,y) || pillar[y][x] && !pillar_test(x,y) || pillar[y][x+1] && !pillar_test(x+1,y))
                    beam[y][x] = true;
            }
            else//건설
                beam[y][x] = beam_test(x,y);
        }
    }
    vector<vector<int>> answer;
    for(int i = 0 ; i <= n; ++i)//세로
        for(int j = 0 ; j <= n ; ++j)//가로
        {
            if(pillar[j][i])
                answer.push_back({i,j,0});
            if(beam[j][i])
                answer.push_back({i,j,1});
        }
    return answer;
}