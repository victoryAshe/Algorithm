//같은 숫자는 싫어: https://programmers.co.kr/learn/courses/30/lessons/12906

#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr[0]);

    int i, j;
    for (i = 1; i < arr.size(); i++)
    {
        j = arr[i - 1];
        if (arr[i] != j) answer.push_back(arr[i]);
    }

    return answer;
}