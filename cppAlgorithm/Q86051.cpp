// 없는 숫자 더하기: https://programmers.co.kr/learn/courses/30/lessons/86051
// sort를 우선 하고 해봤는데 그러면 시간 초과가 떴다. 제한사항이 0~9까지인 숫자이므로 그냥 brute-force 해주었음.
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
    int i, answer = 0;
    for (i = 0; i < 10; i++)
        if (find(numbers.begin(), numbers.end(), i) == numbers.end())
            answer += i;
    return answer;
}