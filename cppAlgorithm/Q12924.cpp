// 숫자의 표현: https://programmers.co.kr/learn/courses/30/lessons/12924
using namespace std;

int solution(int n) {
    int answer = 0;
    int i, p = 1;
    while (p<=n)
    {
        int added = 0;
        for (i = p; i <= n; i++)
        {
            added += i;
            if (added >= n)
            {
                if (added == n) answer++;
                p++;
                break;
            }
        }
    }

    return answer;
}