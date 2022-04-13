// 예산: https://programmers.co.kr/learn/courses/30/lessons/12982
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int added = 0, i;
    // d의 모든 숫자 합을 구하고 budget 이하인지 비교하여 합한 개수의 최댓값을 return
    sort(d.begin(), d.end());
    for (int x : d) added += x;
    for (i = d.size(); i > 0; i--)
    {
        if (added <= budget) return i;
        added -= d[i - 1];
    }
}