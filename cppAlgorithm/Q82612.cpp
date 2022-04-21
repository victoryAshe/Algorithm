// 부족한 금액 계산하기: https://programmers.co.kr/learn/courses/30/lessons/82612
using namespace std;

long long solution(int price, int money, int count)
{
    long long cost = 0; int i;
    for (i = 1; i <= count; i++) cost += price * i;
    return cost > money ? cost - money : 0;
}