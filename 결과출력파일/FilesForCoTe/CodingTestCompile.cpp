#include <vector>
#include <climits>

using namespace std;

vector<vector<int>> solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    return {{1,2,3},{1,2,3}};
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define ARGUMENTS                ((  10,10,[100],[100],[11],[11]	 )) // <- 괄호 두 쌍 안에 인수 입력
#define TYPE_OF_ARGUMENTS        int, int, vector<int>, vector<int>, vector<int>, vector<int>
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "FunctionReturnPrint.cpp"
int main()
{
    FunctionReturnPrint<TYPE_OF_ARGUMENTS>(solution,TO_STRING(ARGUMENTS));
    return 0;
}
