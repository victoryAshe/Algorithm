// 2020 카카오_문자열 압축: https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string s) {
    int answer = 0;
    string shortest = s;
    int i, j, iter;
    for (i = 1; i <= (int)s.length() / 2; i++)
    {
        string start = "", temp = "", target = "";
        iter = 0;
        for (j = 0; j <= s.length(); j += i)
        {
            if (s.substr(j, i) == start)
            {
                if (temp.length() != 0) iter++;
                else
                {
                    if (target.substr(target.length() - i) == start)
                        target = target.substr(0, target.length() - i);
                    iter = 2;
                }
                temp = to_string(iter) + start;
            }
            else
            {
                start = s.substr(j, i);
                if (temp.length() != 0)
                {
                    target += temp;
                    temp = "";
                    iter = 0;
                }
                target += start;
            }
        }

        if (target.length() < shortest.length()) shortest = target;
    }

    answer = shortest.length();
    return answer;
}