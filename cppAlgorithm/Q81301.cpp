// [2021 카카오] 숫자 문자열과 영단어: https://programmers.co.kr/learn/courses/30/lessons/81301?language=cpp
// 배운 것: regx_replace(string s, regex(string target_string), string change_string);
#include <string>
#include <regex>
using namespace std;

int solution(string s) {
    /*
    * for(int i = 0; i<s.size(); i++) if (s.substr(i, 4) == "zero") { a += '0'; i += 3; }  ...
    * 위와 같은 방법을 사용할 경우 굉장히 빠르게 처리되지만, 코드가 더럽다!
    * 아래와 같은 방법을 사용할 경우 처리 속도는 조금 느려지지만, 코드가 정돈되어있다.
    */

    int i;
    s = regex_replace(s, regex("zero"), "0");
    s = regex_replace(s, regex("one"), "1");
    s = regex_replace(s, regex("two"), "2");
    s = regex_replace(s, regex("three"), "3");
    s = regex_replace(s, regex("four"), "4");
    s = regex_replace(s, regex("five"), "5");
    s = regex_replace(s, regex("six"), "6");
    s = regex_replace(s, regex("seven"), "7");
    s = regex_replace(s, regex("eight"), "8");
    s = regex_replace(s, regex("nine"), "9");

    return stoi(s);
}