#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int comparation (vector<int> vec1, vector<int> vec2)
{
    vector<int> numbersA;
    for(int i = vec1[0] ; i >= 2  ; i--)
        if(vec1[0]%i == 0)
            numbersA.push_back(i);
    for(int k = 0 ; k < vec1.size() ; k++)
        for(int i = 0 ; i < numbersA.size() ; i++)
            if(vec1[k]%numbersA[i] != 0 || vec2[k]%numbersA[i] == 0)
            {
                numbersA.erase(numbersA.begin()+i);
                i--;
            }
    if(numbersA.size() > 0)
        return numbersA[0];
    else
        return 0;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    sort(arrayA.begin(),arrayA.end());
    return max(comparation(arrayA,arrayB),comparation(arrayB,arrayA));  
}