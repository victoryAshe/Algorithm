// 가운데 글자 가져오기: https://programmers.co.kr/learn/courses/30/lessons/12903?language=cpp
#include <string>
using namespace std;

string solution(string s) {
    return s.size() % 2 == 0 ? s.substr(s.size() / 2 - 1, 2) : s.substr(((int)s.size()/2),1);
}