// 2017 팁스타운_ 예상 대진표: https://programmers.co.kr/learn/courses/30/lessons/12985
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    int counterA = 0;
    while (true)
    {
        answer++;
        counterA = a % 2 == 0 ? a - 1 : a + 1;
        if (counterA == b) break;

        a = a % 2 == 0 ? a / 2 : (a + 1) / 2;
        b = b % 2 == 0 ? b / 2 : (b + 1) / 2;
    }

    return answer;
}