// 2020 카카오_ 수식 최대화: https://programmers.co.kr/learn/courses/30/lessons/67257
// 아직 못 풀었음
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

long long solution(string expression) {
    long long answer = 0;
    vector<int> numbers;
    vector<char> operators;
    int i, j; string num = "";
    for (i = 0; i < expression.length(); i++)
    {
        if (isdigit(expression[i]))
            num += expression[i];
        else
        {
            numbers.push_back(stoi(num));
            num = "";
            operators.push_back(expression[i]);
        }
    }
    vector<char> uniqueO = operators;
    sort(uniqueO.begin(), uniqueO.end());
    uniqueO.erase(unique(uniqueO.begin(), uniqueO.end()), uniqueO.end());
    int max = factorial(uniqueO.size());

    /*
    for (char x : uniqueO) cout << x << " ";
    cout << endl;
    */
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < operators.size(); j++)
        {

        }
    }
    


    return answer;
}