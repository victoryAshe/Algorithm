// 하샤드 수: https://programmers.co.kr/learn/courses/30/lessons/12947?language=cpp
#include <string>
using namespace std;

bool solution(int x) {
	string a = to_string(x);
	int i, y = 0;
	for (i = 0; i < a.size(); i++) y += a[i] - 48;
	return x % y == 0;
}