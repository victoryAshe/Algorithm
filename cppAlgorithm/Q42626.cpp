// �� �ʰ�: https://programmers.co.kr/learn/courses/30/lessons/42626
// ��͸� �̿��� ��� -> ��Ȯ���� ��������� ȿ���������� ���� ������
#include <vector>
#include <algorithm>
using namespace std;
int answer;

void recursion(vector<int>scoville, int K)
{
    sort(scoville.begin(), scoville.end());
    if (scoville[0] >= K) return;
    if (scoville.size() < 2)
    {
        answer = -1;
        return;
    }
    scoville.push_back(scoville[0] + scoville[1] * 2);
    scoville.erase(scoville.begin()); scoville.erase(scoville.begin());
    answer++;
    recursion(scoville, K);
}

int solution(vector<int> scoville, int K) {

    recursion(scoville, K);
    return answer;
}