// ���ڼ��ڼ��ڼ��ڼ��ڼ�?: https://programmers.co.kr/learn/courses/30/lessons/12922?language=cpp
#include <string>
using namespace std;

string solution(int n) {
    int i; string answer = "";
    for (i = 0; i < n; i++) i % 2 == 0 ? answer.append("��") : answer.append("��");

    return answer;
}