// ¾à¼öÀÇ °³¼ö¿Í µ¡¼À: https://programmers.co.kr/learn/courses/30/lessons/77884?language=cpp
using namespace std;

int solution(int left, int right) {
    int answer = 0, i, j, k;
    for (i = left; i <= right; i++)
    {
        k = 0;
        for (j = 1; j <= i; j++) if (i % j == 0) k++;
        answer += k % 2 == 0 ? i : -i;
    }
    return answer;
}