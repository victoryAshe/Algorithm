// 나머지가 1이 되는 수 찾기: https://programmers.co.kr/learn/courses/30/lessons/87389
using namespace std;

int solution(int n) {
    int i;
    for (i = 1; i < n; i++) if (n % i == 1) return i;
}