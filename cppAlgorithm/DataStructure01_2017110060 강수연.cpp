// 22-1 �ڷᱸ�� ���� 01: ���� ��� ���α׷�
#include <iostream>
using namespace std;
const int Student = 10, Sub = 1;
int main()
{ 
	cout << fixed; cout.precision(1);
	int score[Sub][Student] = { {75, 60, 88, 100, 54, 70, 85, 80, 95, 10} };
	string names[Sub] = { "����" };
	int i, j; double answer;

	for (i = 0; i < Sub; i++)
	{
		answer = 0;
		for (j = 0; j < Student; j++) answer += score[i][j];
		answer =  (double) answer/ Student;
		cout << names[i] << " ������ ����� " << answer << "�Դϴ�."<< endl;
	}
	

	return 0;
}