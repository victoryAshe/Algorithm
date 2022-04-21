// 22-1 자료구조 과제 02: 성적 계산 프로그램
#include <iostream>
using namespace std;
const int Student = 10, Sub = 3;
int main()
{
	cout << fixed; cout.precision(1);
	int score[Sub][Student] = { {75, 60, 88, 100, 54, 70, 85, 80, 95, 10},
		{85, 80, 89, 100, 100, 70, 85, 80, 95, 10},
		{70, 50, 80, 79, 85, 70, 85, 80, 95, 10} };
	string names[Sub] = { "국어", "영어", "수학"};
	int i, j; double answer;

	for (i = 0; i < Sub; i++)
	{
		answer = 0;
		for (j = 0; j < Student; j++) answer += score[i][j];
		answer = (double)answer / Student;
		cout << names[i] << " 과목의 평균은 " << answer << "입니다." << endl;
	}


	return 0;
}