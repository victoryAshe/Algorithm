// 카펫: https://programmers.co.kr/learn/courses/30/lessons/42842
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size, len, i, h, w;
    size = brown + yellow;
    len = brown + 4;

    for (i = 1; i < size; i++) if (size % i == 0)
    {
        h = size / i;
        if (h * 2 + i * 2 == len)
        {
            w = h < i ? i : h;
            if (h == w) h = i;
            answer.push_back(w); answer.push_back(h);
            break;
        }
    }


    return answer;
}