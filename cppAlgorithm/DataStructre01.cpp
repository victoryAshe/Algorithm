// 22-1 �ڷᱸ�� ���� 01: ���� ��� ��� ���α׷�
#include <iostream>
#include <random>
using namespace std;
int main()
{
	// �õ� ���� ��� ���� random_device ����
	random_device rd;

	// random_device������ ���� ���� ���� �ʱ�ȭ
	mt19937 gen(rd());

	// �յ��ϰ� ��Ÿ�� ������ ������ ���� �յ� ���� ����
	uniform_int_distribution<int> dis(0, 100);

	//��/����/�л�
	int scores[3][3][9];
	string subjects[3] = { "����", "����", "����" };
	
	// ������ ���� �־����� �ʾ� ������ �����߽��ϴ�.
	int i, j, k;
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) for (k = 0; k < 9;k++) scores[i][j][k] = dis(gen);

	// �ݺ� ���� ���� ��
	float sum;
	// ���� ���� ��
	float sum2[3] = { 0, 0, 0 };

	// ��µǴ� float���� �Ҽ��� �ڸ����� ����: 1�ڸ������� ���
	cout << fixed;
	cout.precision(1);
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = 0;
			for (k = 0; k < 9; k++) sum += scores[i][j][k];
			cout << i + 1 << "���� " << subjects[j] << " ���� ���: " << sum / 9 << endl;
			sum2[j] += sum;
		}
		
		cout << endl;
	}
	for (j = 0; j < 3; j++) cout << "3�г��� " << subjects[j] << " ���� ���: " << sum2[j] / 27 << endl;
		
	

	return 0;
}