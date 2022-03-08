// [2021 īī��] ���� ���ڿ��� ���ܾ�: https://programmers.co.kr/learn/courses/30/lessons/81301?language=cpp
// ��� ��: regx_replace(string s, regex(string target_string), string change_string);
#include <string>
#include <regex>
using namespace std;

int solution(string s) {
    /*
    * for(int i = 0; i<s.size(); i++) if (s.substr(i, 4) == "zero") { a += '0'; i += 3; }  ...
    * ���� ���� ����� ����� ��� ������ ������ ó��������, �ڵ尡 ������!
    * �Ʒ��� ���� ����� ����� ��� ó�� �ӵ��� ���� ����������, �ڵ尡 �����Ǿ��ִ�.
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