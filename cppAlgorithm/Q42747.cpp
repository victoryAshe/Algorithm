// H-Index: https://programmers.co.kr/learn/courses/30/lessons/42747
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0, h, idx;
    sort(citations.begin(), citations.end());

    int size = citations.size() - 1;
    for (h = 0; h < citations[size]; h++)
    {
        idx = 0;
        for (int x : citations) if (x >= h) idx++;
        if (idx >= h && h > answer) answer = h;
    }

    return answer;
}