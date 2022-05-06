// 최솟값 만들기: https://programmers.co.kr/learn/courses/30/lessons/12941
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    int i;
    for(i = 0; i<a.size(); i++)
        answer += a[i] * b[i];

    return answer;
}