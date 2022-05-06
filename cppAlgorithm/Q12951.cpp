// JadenCase 문자열 만들기: https://programmers.co.kr/learn/courses/30/lessons/12951
#include <string>
using namespace std;

string solution(string s) {
    string answer = s;
    if (isalpha(answer[0]) && answer[0] > 90) answer[0] -= 32;
    
    int i;
    for (i = 1; i < s.length(); i++) 
        if (isalpha(answer[i]))
        {
            if (answer[i - 1] == ' ')
            {
                if (answer[i] > 90) answer[i] -= 32;
            }
            else if (answer[i] <= 90) answer[i] += 32;
        }
    return answer;
}