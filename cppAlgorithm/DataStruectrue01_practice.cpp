#include <iostream>
using namespace std;
#define ST_NUM 20				// C ��Ÿ��
const int StudentNumber = 20;	// C++ ��Ÿ��
void main()
{
	// TODO: ST_NUM ���� ���� ��� ���ϱ�
	int scores[ST_NUM];
	for (int st = 0; st < StudentNumber; st++)
	{
		cout << st + 1 << "��° �л� ������ �Է��ϼ���: ";
		cin >> scores[st];
	}
	int sum = 0;
	for (int i = 0; i < ST_NUM; i++) sum += scores[i];
	double average = (double) sum / ST_NUM;
	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}