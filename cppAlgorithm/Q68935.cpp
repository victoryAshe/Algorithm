// 3진법 뒤집기: https://programmers.co.kr/learn/courses/30/lessons/68935?language=cpp
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n) {
    string a; int i = 1, b;

    //3진법 구현
    while (n > 0)
    {
        b = n % 3 == 0 ? 0 : n % 3;
        a.insert(a.begin(), b + 48);
        n = n >= 3 ? n /= 3 : 0;
    }

    //앞뒤 반전
    reverse(a.begin(), a.end());

    //10진법 변환
    b = a.size();
    while (a.size() > 0)
    {
        if (a[0] == '0')
        {
            a.erase(a.begin());
            i++; continue;
        }
        n += pow(3, b - i) * (a[0] - 48);
        a.erase(a.begin());
        i++;
    }

    return n;
}