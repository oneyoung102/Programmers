//2025-03-28 12:36:22
//https://school.programmers.co.kr/learn/courses/30/lessons/340206

#include <iostream>

using namespace std;

int main(void) {
    int angle1;
    int angle2;
    cin >> angle1 >> angle2;
    
    int sum_angle = (angle1 + angle2)%360;
    cout << sum_angle << endl;
    return 0;
}
