// 22-1 자료구조 과제 04: 학생수와 성적을 입력받는 성적 계산 프로그램
#include <iostream>
using namespace std;
int main()
{
	cout << fixed; cout.precision(1);
	
	int Student, i, sum = 0, *p;

	cout << "학생 수를 입력하시오: ";
	cin >> Student; 
	cout << endl;

	p= new int[Student];

	cout << "각 학생의 점수를 입력하시오: ";
	for (i = 0; i < Student; i++)
	{
		cin >> p[i]; sum += p[i];
	}
	cout << endl;

	cout << "학생 " << Student << "명의 수학 과목 평균은 " << (double)sum / Student << "점입니다." <<endl;

	return 0;
}