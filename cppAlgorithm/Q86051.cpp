// ���� ���� ���ϱ�: https://programmers.co.kr/learn/courses/30/lessons/86051
// sort�� �켱 �ϰ� �غôµ� �׷��� �ð� �ʰ��� ����. ���ѻ����� 0~9������ �����̹Ƿ� �׳� brute-force ���־���.
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int i, answer = 0;
    for (i = 0; i < 10; i++)
        if (find(numbers.begin(), numbers.end(), i) == numbers.end())
            answer += i;
    return answer;
}