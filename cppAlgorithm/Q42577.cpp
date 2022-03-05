// ��ȭ��ȣ ���: https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> pb) {
    // ���� ���� ��ȣ�� ������ ��� sort�� �ϸ� �ٷ� �ڿ� ���� ������, sort�� ���ָ� �ݺ����� �ϳ��� �ᵵ �ȴ�!
    sort(pb.begin(), pb.end());

    int i;
    for (i = 0; i < pb.size() - 1; i++)
        if (pb[i+1].find(pb[i]) == 0)
            return false;

    return true;
}