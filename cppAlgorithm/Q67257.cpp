// 2020 카카오_ 수식 최대화: https://programmers.co.kr/learn/courses/30/lessons/67257
// 아직 못 풀었음
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*
* [Idea]
* 중위 표기식 -> 후위표기식처럼 나누고,
* operator 우선순위를 만든 뒤(permutation 리스트) 각각에 대하여 계산
*/

vector<int> nums;
vector<char> operators;

void getExp(string exp)
{
    string num = "";
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];
        if (ch == '+' || ch == '-' || ch == '*')
        {
            operators.push_back(ch);
            nums.push_back(stoi(num));
            num = "";
        }
        else
            num += ch;
            
    }
}


long long solution(string expression) {
    long long answer = 0;

    getExp(expression);
    int plus, sub, mul;
    plus = count(operators.begin(), operators.end(), '+');
    sub = count(operators.begin(), operators.end(), '-');
    mul = count(operators.begin(), operators.end(), '*');



    return answer;
}