// 22-1 �ڷᱸ�� ���� 04: �л����� ������ �Է¹޴� ���� ��� ���α׷�
#include <iostream>
using namespace std;
int main()
{
	cout << fixed; cout.precision(1);
	
	int Student, i, sum = 0, *p;

	cout << "�л� ���� �Է��Ͻÿ�: ";
	cin >> Student; 
	cout << endl;

	p= new int[Student];

	cout << "�� �л��� ������ �Է��Ͻÿ�: ";
	for (i = 0; i < Student; i++)
	{
		cin >> p[i]; sum += p[i];
	}
	cout << endl;

	cout << "�л� " << Student << "���� ���� ���� ����� " << (double)sum / Student << "���Դϴ�." <<endl;

	return 0;
}