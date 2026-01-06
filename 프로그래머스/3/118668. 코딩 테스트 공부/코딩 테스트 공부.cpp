#include <vector>
#include <climits>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int alp_max = 0, cop_max = 0;
    for(const auto& problem : problems)
    {
        alp_max = max(alp_max,problem[0]);
        cop_max = max(cop_max,problem[1]);
    }
    alp = min(alp,alp_max);
    cop = min(cop,cop_max);
    vector<vector<int>> dp(alp_max+1,vector<int>(cop_max+1,INT_MAX)); //alp,cop일 떄 최소 비용
    dp[alp][cop] = 0;
    for(int a = alp ; a <= alp_max ; ++a)
        for(int c = cop ; c <= cop_max ; ++c)
            dp[a][c] = a-alp+c-cop;
    for(int a = alp ; a <= alp_max ; ++a)
        for(int c = cop ; c <= cop_max ; ++c)
            for(const auto& problem : problems)
                if(a >= problem[0] && c >= problem[1])
                {
                    const int next_alp = min(a+problem[2],alp_max), next_cop = min(c+problem[3],cop_max);
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop],dp[a][c]+problem[4]);
                }
    return dp[alp_max][cop_max];
}