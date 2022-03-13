// 22-1 자료구조 과제 01: 성적 계산 프로그램
#include <iostream>
using namespace std;
const int Student = 10, Sub = 1;
int main()
{ 
	cout << fixed; cout.precision(1);
	int score[Sub][Student] = { {75, 60, 88, 100, 54, 70, 85, 80, 95, 10} };
	string names[Sub] = { "수학" };
	int i, j; double answer;

	for (i = 0; i < Sub; i++)
	{
		answer = 0;
		for (j = 0; j < Student; j++) answer += score[i][j];
		answer =  (double) answer/ Student;
		cout << names[i] << " 과목의 평균은 " << answer << "입니다."<< endl;
	}
	

	return 0;
}