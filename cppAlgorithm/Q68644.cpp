// 두 개 뽑아서 더하기: https://programmers.co.kr/learn/courses/30/lessons/68644?language=cpp
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int i, j, k;  vector<int> answer;
    for (i = 0; i < numbers.size(); i++) for (j = i + 1; j < numbers.size(); j++)
    {
        k = numbers[i] + numbers[j];
        if (find(answer.begin(), answer.end(), k) == answer.end()) answer.push_back(k);
    }
    sort(answer.begin(), answer.end());
    return answer;
}