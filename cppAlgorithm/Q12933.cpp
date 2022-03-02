// 정수 내림차순으로 배치하기: https://programmers.co.kr/learn/courses/30/lessons/12933?language=cpp
// 삽입 정렬 사용
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {

    string a = to_string(n);
	int i,j,tmp;

	for (i = 1; i < a.size(); i++) {
		tmp = a[i];
		j = 0;
		for (j = i - 1; j > -1; j--) {
			if (a[j] > tmp) {
				a[j + 1] = a[j];
			}
			else {
				break;
			}
		}
		a[j + 1] = tmp;
	}
    return stoll(a);

	/*
	* //다른 사람의 풀이: algorithm: sort 사용
	* #include <string>
	*#include <vector>
	*#include <algorithm>
	*using namespace std;

	*long long solution(long long n) {
	*	string str = to_string(n);
	*	sort(str.begin(), str.end(), greater<char>());
	*	return stoll(str);	
	*}
    */

}

