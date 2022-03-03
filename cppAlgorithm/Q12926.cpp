// 시저 암호: https://programmers.co.kr/learn/courses/30/lessons/12926
#include <string>
#include <cctype>
using namespace std;

string solution(string s, int n) {
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (isblank(s[i])) continue;
        if (isupper(s[i])) s[i] = s[i] + n <= 90 ? s[i] + n : s[i] + n - 90;
        else s[i] = s[i] + n <= 122 ? s[i] + n : s[i] + n - 122;
        
    }

    return s;
}