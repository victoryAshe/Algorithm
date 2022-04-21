// 문자열 내림차순으로 배치하기: https://programmers.co.kr/learn/courses/30/lessons/12917?language=cpp
#include <string>
#include <algorithm>
using namespace std;

string solution(string s) {
    sort(s.begin(), s.end(), greater<char>());
    return s;
}