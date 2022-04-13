// 더 맵게: https://programmers.co.kr/learn/courses/30/lessons/42626\
// 우선순위 큐: https://breakcoding.tistory.com/123
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0, first, second;
    //우선 순위 큐 생성
    priority_queue<int, vector<int>, greater<int> > p(scoville.begin(), scoville.end());

    while (p.size() > 1 && p.top() < K)
    {
        first = p.top(); p.pop();
        second = p.top(); p.pop();
        p.push(first + (second * 2));
        answer++;
    }

    if (p.top() < K) return -1;
    return answer;
}



/*
// 재귀를 이용한 방법 -> 정확성은 통과하지만 효율성에서는 전부 실패함
#include <vector>
#include <algorithm>
using namespace std;
int answer;

void recursion(vector<int>scoville, int K)
{
    sort(scoville.begin(), scoville.end());
    if (scoville[0] >= K) return;
    if (scoville.size() < 2)
    {
        answer = -1;
        return;
    }
    scoville.push_back(scoville[0] + scoville[1] * 2);
    scoville.erase(scoville.begin()); scoville.erase(scoville.begin());
    answer++;
    recursion(scoville, K);
}

int solution(vector<int> scoville, int K) {

    recursion(scoville, K);
    return answer;
}
*/