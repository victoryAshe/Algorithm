// 자연수 뒤집어 배열로 만들기: https://programmers.co.kr/learn/courses/30/lessons/12932?language=cpp
#include <string>
#include <vector>
using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int i;  string a = to_string(n);
    for (i = a.size() - 1; i >= 0; i--)answer.push_back(a[i] - 48);
    return answer;
}