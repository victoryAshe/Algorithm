// ����: https://programmers.co.kr/learn/courses/30/lessons/42578
// ����� ��: ��� ���� �Ա�/���Ա��� �������� ���� 
// -> (������ ���� �� + 1)�� ��� ���ϰ� �ƹ��͵� ������ ������ 1�� ���ش�.
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, vector<string>> closet;
    map<string, vector<string>>::iterator p;

    for (vector<string> x : clothes)
    {
        if (closet.find(x[1]) != closet.end())
            closet[x[1]].push_back(x[0]);
        else  closet[x[1]] = { x[0] };
    }

    for (p = closet.begin(); p != closet.end(); p++)
        answer *= p->second.size() + 1;

    return answer - 1;
}