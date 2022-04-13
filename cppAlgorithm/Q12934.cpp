// 정수 제곱근 판별: https://programmers.co.kr/learn/courses/30/lessons/12934?language=cpp
#include <cmath>
using namespace std;

long long solution(long long n) {
    return sqrt(n) - int(sqrt(n)) == 0 ? pow(sqrt(n) + 1, 2) : -1;
}