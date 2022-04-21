// 로또의 최고 순위와 최저 순위: https://programmers.co.kr/learn/courses/30/lessons/77484?language=cpp
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> nums) {
    int a = 7, b = 0, i;
    vector<int>::iterator p;
    for (i = 0; i < nums.size(); i++)
    {
        p = find(lottos.begin(), lottos.end(), nums[i]);
        if (p != lottos.end()) a--;
        if (lottos[i] == 0) b++;
    }
    if (a == 7) a = 6; if (a - b == 0) b = 5;
    return { a - b, a };
}