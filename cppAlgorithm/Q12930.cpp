// 이상한 문자 만들기: https://programmers.co.kr/learn/courses/30/lessons/12930?language=cpp
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    int i, j;
    for (i = 0; i < s.size(); i++) 
    {
        if (isblank(s[i]))
        {
            j = 0; continue;
        }

        if (j % 2 == 0 && islower(s[i])) s[i] = toupper(s[i]);
        else if (j % 2 == 1 && isupper(s[i])) s[i] = tolower(s[i]);
        j++;
    }
    
    return s;
}