#include <iostream>
using namespace std;

void main() {
	char* p;
	int num;
	cout << "�Ҵ��� ������ ����: ";
	cin >> num;
	cout << endl;
	p = new char[num];
	cout << "�Ҵ��� ���� " << num << "��: ";
	for (int i = 0; i < num; i++) cin >> p[i];
	cout << endl;
	for (int i = 0; i < num; i++) cout << p[i] << " ";
	cout << endl;
	delete p;
}
