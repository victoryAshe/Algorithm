// 다리를 지나는 트럭: https://programmers.co.kr/learn/courses/30/lessons/42583
#include <vector>
#include <algorithm>
using namespace std;

int solution(int bridge_length, int weight, vector<int> tw) {
    if (tw.size() == 1) return bridge_length + 1;

    int answer = 0, i = 0, next, bweight = 0;
    vector<int> bridge(bridge_length, 0), waiting;
    waiting.assign(tw.begin(), tw.end());

    while (waiting.size() > 0 || bweight > 0)
    {
        if (bridge[0] != 0) bweight -= bridge[0];
        for (i = 0; i < bridge.size() - 1; i++) bridge[i] = bridge[i + 1];
        bridge[bridge_length - 1] = 0;

        if (waiting.size() > 0) if (bweight + waiting[0] <= weight)
        {
            bridge[bridge_length - 1] = waiting[0];
            bweight += waiting[0];
            waiting.erase(waiting.begin());
        }

        answer++;
    }

    return answer;
}