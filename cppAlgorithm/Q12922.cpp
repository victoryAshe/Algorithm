// 수박수박수박수박수박수?: https://programmers.co.kr/learn/courses/30/lessons/12922?language=cpp
#include <string>
using namespace std;

string solution(int n) {
    int i; string answer = "";
    for (i = 0; i < n; i++) i % 2 == 0 ? answer.append("수") : answer.append("박");

    return answer;
}