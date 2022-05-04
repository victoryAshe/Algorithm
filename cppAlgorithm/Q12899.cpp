// 124 나라의 숫자: https://programmers.co.kr/learn/courses/30/lessons/12899
#include <string>
using namespace std;

/*
* [Idea]
* 3진법을 비틀어 0을 포함!
* 3으로 나누어 떨어질 때, 몫-=1, 나머지  = 4 로 반환한다.
*/

string solution(int n) {
    string answer = "";
    int rest;

    while (n > 0)
    {
        rest = n % 3 == 0 ? 4 : n % 3;
        answer.insert(answer.begin(), rest + 48);
        n = rest == 4 ? n /3 - 1 : n/3;

    }

    return answer;
}

/*
* // 효율성 테스트 실패
void number(string& num, int idx)
{
    int size = num.length();

    if (num[size - idx] == '1')
        num[size - idx] = '2';
    else if (num[size - idx] == '2')
        num[size - idx] = '4';
    else
    {
        num[size - idx] = '1';
        if (size - (idx + 1) >= 0) number(num, ++idx);
        else num = '1' + num;
    }

}

string solution(int n) {
    if (n == 1) return "1";

    string answer = "1";
    int i, idx = 1;
    for (i = 2; i <= n; i++)
        number(answer, idx);

    return answer;
}
*/