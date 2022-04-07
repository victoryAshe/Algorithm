// ���� �� �ִܰŸ�: https://programmers.co.kr/learn/courses/30/lessons/1844
#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 1;
    if (maps[maps.size() - 1][maps[0].size() - 2] == 0
        && maps[maps.size() - 2][maps[0].size() - 1] == 0) return -1;

    int x = 0, y = 0;   //ĳ������ ��ǥ
    while (x < maps.size() - 1 && y < maps[0].size() - 1)
    {
        if (maps[x + 1][y] == 1) x++;
        else if (maps[x][y + 1] == 1) y++;
        else if (maps[x - 1][y] == 1) x--;
        answer++;
    }

    return answer;
}