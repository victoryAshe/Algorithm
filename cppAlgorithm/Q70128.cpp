// ����: https://programmers.co.kr/learn/courses/30/lessons/70128
#include <vector>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0, i;
    for (i = 0; i < a.size(); i++) answer += a[i] * b[i];
    return answer;
}