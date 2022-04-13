//문자열 내 p와 y의 개수: https://programmers.co.kr/learn/courses/30/lessons/12916

#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int i, j = 0;
    for (i = 0; i < s.size(); i++)
    {
        if ((s[i] & 31) == 16) j++;
        else if ((s[i] & 31) == 25) j--;
    }

    return j == 0;

}