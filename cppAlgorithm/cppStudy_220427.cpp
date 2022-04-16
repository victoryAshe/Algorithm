#include <iostream>
using namespace std;

void main() {
	char* p;
	int num;
	cout << "할당할 정수의 개수: ";
	cin >> num;
	cout << endl;
	p = new char[num];
	cout << "할당할 정수 " << num << "개: ";
	for (int i = 0; i < num; i++) cin >> p[i];
	cout << endl;
	for (int i = 0; i < num; i++) cout << p[i] << " ";
	cout << endl;
	delete p;
}
