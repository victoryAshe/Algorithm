// 최소직사각형: https://programmers.co.kr/learn/courses/30/lessons/86491
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int i; vector<int> s1, s2;
    for (vector<int> x: sizes)
    {
        s1.push_back(x[0]); s2.push_back(x[1]);
    }
    int a = *max_element(s1.begin(), s1.end());
    int b = *max_element(s2.begin(), s2.end());
    for(i = 0 ; i<sizes.size(); i++)
    {

    }

    return a * b;
}