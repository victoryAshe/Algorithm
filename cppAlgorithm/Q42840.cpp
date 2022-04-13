// 모의고사: https://programmers.co.kr/learn/courses/30/lessons/42840
// 배운 것: int they_max = *max_element(they.begin(),they.end());
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer; vector<int> corrects(3, 0); int i;
    // 각 학생의 맞은 개수를 계산
    vector<int> g1 = { 1, 2, 3, 4, 5 };
    vector<int> g2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> g3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    for (i = 0; i < answers.size(); i++)
    {
        if (answers[i] == g1[i % g1.size()]) corrects[0]++;
        if (answers[i] == g2[i % g2.size()]) corrects[1]++;
        if (answers[i] == g3[i % g3.size()]) corrects[2]++;
    }

    // 맞은 개수 비교
    int max = *max_element(corrects.begin(), corrects.end());
    for (i = 0; i < 3; i++) if (corrects[i] == max) answer.push_back(i + 1);

    return answer;
}