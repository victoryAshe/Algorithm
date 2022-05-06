// 2020카카오_괄호 변환: https://programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>
using namespace std;

/*
* 1. 입력이 빈 문자열인 경우, 빈 문자열 반환 
* 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리 (단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없고, v는 빈 문자열이 될 수 있음)
* 3. if (string u == "올바른 괄호 문자열")  
*   3-1. return u + (string v를 1단계부터 재귀 수행한 결과)
* 4. if (string u != "올바른 괄호 문자열") 
*   4-1. string x = '('
*   4-2. x += (string v를 1단계부터 재귀 수행한 결과)
*   4-3. x+= ')'
*   4-2. x += u의 첫 번째와 마지막 문자를 제거한 나머지의 괄호 방향을 뒤집기
*   4-3. return x;
*/

bool checkBracket(string s)
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

string solution(string w) {
    string answer = "";
    if (w.length() == 0) return answer; // 1
    int i, a = 0, b = 0;
    string u, v;
    for (i = 0; i < w.length(); i++)    // 2
    {
        if (w[i] == 40) a++; else b++;

        if (a != 0 && a == b)
        {
            u = w.substr(0, i + 1);
            v = w.substr(i + 1);
            break;
        }
    }

    if (checkBracket(u)) return u + solution(v);    // 3
    else                                            // 4
    {
        answer = '(' + solution(v) + ')';        
        u = u.substr(1, u.length() - 2);
        for (i = 0; i < u.length(); i++)
            u[i] = u[i] == 40 ? 41 : 40;
        answer += u;
    }
    return answer;
}