// 최소직사각형: https://programmers.co.kr/learn/courses/30/lessons/86491
// Idea: 어차피 최댓값을 반환하는 것이기 때문에, 긴 부분을 무조건 가로로 정해 넓이의 최댓값을 구한다.
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> s) {

	vector<int> w, h;
	for (vector<int> x : s)
	{
		if (x[0] < x[1])
		{
			w.push_back(x[1]); h.push_back(x[0]);
		}
		else
		{
			w.push_back(x[0]); h.push_back(x[1]);
		}
	}

	return *max_element(w.begin(), w.end()) * *max_element(h.begin(), h.end());

}