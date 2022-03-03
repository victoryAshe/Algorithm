// 2016³â: https://programmers.co.kr/learn/courses/30/lessons/12901?language=cpp
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int a, int b) {
    vector<int> month31 = { 1, 3, 5, 7, 8, 10, 12 };
    vector<int> month30 = { 4, 6, 9, 11 };

    int i, day = b - 1;
    for (i = 1; i < a; i++)
    {
        if (find(month31.begin(), month31.end(), i) != month31.end())
            day += 31;
        else if (find(month30.begin(), month30.end(), i) != month30.end())
            day += 30;
        else day += 29;
    }

    switch (day % 7) {
    case 0:
        return "FRI";
        break;
    case 1:
        return "SAT";
        break;
    case 2:
        return "SUN";
        break;
    case 3:
        return "MON";
        break;
    case 4:
        return "TUE";
        break;
    case 5:
        return "WED";
        break;
    case 6:
        return "THU";
        break;

    }
}