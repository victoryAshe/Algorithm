// 전화번호 목록: https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> pb) {
    // 같은 접두 번호로 시작할 경우 sort를 하면 바로 뒤에 오기 때문에, sort를 해주면 반복문을 하나만 써도 된다!
    sort(pb.begin(), pb.end());

    int i;
    for (i = 0; i < pb.size() - 1; i++)
        if (pb[i+1].find(pb[i]) == 0)
            return false;

    return true;
}