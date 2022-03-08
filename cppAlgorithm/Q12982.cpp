// ����: https://programmers.co.kr/learn/courses/30/lessons/12982
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int added = 0, i;
    // d�� ��� ���� ���� ���ϰ� budget �������� ���Ͽ� ���� ������ �ִ��� return
    sort(d.begin(), d.end());
    for (int x : d) added += x;
    for (i = d.size(); i > 0; i--)
    {
        if (added <= budget) return i;
        added -= d[i - 1];
    }
}