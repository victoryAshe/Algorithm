// 소수 찾기: https://programmers.co.kr/learn/courses/30/lessons/12921
// https://notepad96.tistory.com/entry/C-%EC%86%8C%EC%88%98-%ED%8C%90%EB%B3%84%ED%95%98%EA%B8%B0
#include <cmath>
using namespace std;
bool prime(int num) {
    if (num < 2) return false;
    int a = (int)sqrt(num);
    for (int i = 2; i <= a; i++) if (num % i == 0) return false;
    return true;
}
int solution(int n) {
    int i, answer = 0;
    for (i = 0; i <= n; i++) if (prime(i)) answer++;
    return answer;
}