// 음양 더하기: https://programmers.co.kr/learn/courses/30/lessons/76501?language=cpp
#include <vector>
using namespace std;

int solution(vector<int> a, vector<bool> s) {
    int answer = 0, i;
    for (i = 0; i < a.size(); i++) answer += s[i] ? a[i] : -a[i];
    return answer;
}