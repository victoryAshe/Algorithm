// 완주하지 못한 선수: https://programmers.co.kr/learn/courses/30/lessons/42576
// 처음부터 find를 써서 각각 비교하면서 찾는 것보다 sort로 정렬한 뒤 같지 않으면 return하는 것이 빠르다.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> p, vector<string> c) {
    sort(p.begin(), p.end()); sort(c.begin(), c.end());
    int i;
    for (i = 0; i < p.size(); i++) if (p[i] != c[i]) return p[i];
}