// �������� ���� ����: https://programmers.co.kr/learn/courses/30/lessons/42576
// ó������ find�� �Ἥ ���� ���ϸ鼭 ã�� �ͺ��� sort�� ������ �� ���� ������ return�ϴ� ���� ������.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> p, vector<string> c) {
    sort(p.begin(), p.end()); sort(c.begin(), c.end());
    int i;
    for (i = 0; i < p.size(); i++) if (p[i] != c[i]) return p[i];
}