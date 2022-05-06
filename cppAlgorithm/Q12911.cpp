// 다음 큰 숫자: https://programmers.co.kr/learn/courses/30/lessons/12911
#include <string>
#include <algorithm>
using namespace std;

string bin(int n)
{
    string a = "";
    while (n > 0)   //2진수 만들기
    {
        if (n % 2 == 0)
        {
            n /= 2;
            a = '0' + a;
        }
        else
        {
            --n /= 2;
            a = '1' + a;
        }
    }
    return a;
}

int solution(int n) {
    string a = bin(n);
    int target = count(a.begin(), a.end(), '1');
    int m = n;
    while (true)
    {
        m++;
        string b = bin(m);
        if (count(b.begin(), b.end(), '1') == target)
            return m;
    }
}