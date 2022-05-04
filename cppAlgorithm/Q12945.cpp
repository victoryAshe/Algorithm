// 피보나치 수: https://programmers.co.kr/learn/courses/30/lessons/12945
/*
* 단순한 문제로 보이지만, int의 최댓값과 재귀 호출의 깊이에 대한 이해가 필요하다.
* 
* [int의 최댓값에 대해]
* 피보나치 수는 44까지만 가도 int의 최댓값을 초과하므로, 
* (A+B)%C = ((A%C) + (B%C)) % C 라는 수학적 성질을 이용해야 풀 수 있다.
* 
* [재귀 호출의 깊이에 대해]
* 재귀는 반복문에 비해 느리므로, 보통 재귀 호출은 10000번까지 허용한다. 
* 이것을 초과했을 때 런타임 오류가 발생할 수 있다. 
* 이 문제에서는 리스트(check)를 사용해, 재귀 호출의 횟수를 줄여 해결한다.
*/
int* check = new int[100001];

int Fiv(int n)
{
    if (n == 2) return 1;
    if (n == 3) return 2;
    if (check[n] != 0) return check[n];
    check[n] = Fiv(n - 1) % 1234567 + Fiv(n - 2) % 1234567;
    return check[n]%1234567;
}

int solution(int n) {
    int answer;
    answer = Fiv(n);
    return answer;
}