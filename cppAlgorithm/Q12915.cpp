//문자열 내 마음대로 정렬하기: https://programmers.co.kr/learn/courses/30/lessons/12915
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> s, int n) {
    int i;
    for (i = 0; i < s.size(); i++) s[i] = s[i][n] + s[i];
    sort(s.begin(), s.end());
    for (i = 0; i < s.size(); i++) s[i] = s[i].substr(1);
    return s;
}