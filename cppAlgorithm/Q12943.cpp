// �ݶ� ����: https://programmers.co.kr/learn/courses/30/lessons/12943?language=cpp
using namespace std;

int solution(int num) {
    if (num == 1) return 0; //�� ���ǹ��� �߰��ص��� ������ num==1�� �� 3�� return�ȴ�.

    int i; long n = num;
    for (i = 1; i < 501; i++)
    {
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
        if (n == 1) break;
    }
    return i < 500 ? i : -1;
}