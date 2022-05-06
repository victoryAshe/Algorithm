// 올바른 괄호: https://programmers.co.kr/learn/courses/30/lessons/12909
// Q60058: 2020카카오_괄호 변환의 하위 문제라고 할 수 있음
#include<string>
using namespace std;
bool solution(string s)
{
    if (s[0] == 41) return false;
    int i, p = 0, q = 0;
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == 40)
        {
            p = i;
            q = s.find(41, i) > s.find(41, q + 1) ? s.find(41, i) : s.find(41, q + 1);
            if (q == string::npos) return false;
        }
    }
    return true;
}