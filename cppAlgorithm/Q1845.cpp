// ���ϸ�: https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    /*[Idea]
    * 1. nums.size()/2�� ����
    * 2. nums�� ���� ��Ұ� ������ ����
    * 3. return nums.size/2<���� ��Ҽ� ? nums.size/2 : ���� ��� ��
    */
    int answer = (int) nums.size() / 2;

    return answer;
}