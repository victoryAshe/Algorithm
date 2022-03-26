// ¦���� �����ϱ�: https://programmers.co.kr/learn/courses/30/lessons/12973
// �ð����⵵�� ���̱� ���� LIFO������ stack�� ������ ���.
#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    int i;
    vector<char> stack = { s[0] };

    for (i = 1; i < s.size(); i++)
    {
        if (stack[stack.size() - 1] == s[i]) stack.pop_back();
        else stack.push_back(s[i]);

    }

    return stack.size() > 0 ? 0 : 1;
}