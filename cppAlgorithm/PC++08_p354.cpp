#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string prob = "approximately";
	int length = prob.length();
	int tries = 0, maxnum = 0; 
	string answer(length, '-');		// '-'�� �ʱ�ȭ

	cout << "�ִ� �õ� Ƚ��: ";
	cin >> maxnum;
	cout << endl;

	cout << "���� ����: " << answer << endl;
	while (tries < maxnum && answer != prob)
	{
		cout << endl;
		char c;
		cout << "���ڸ� �����Ͻÿ�: ";
		cin >> c;

		//string :: npos�� -1 ���� ��� -> find() �Լ����� �� ã�� ��� return npos
		if(answer.find(c) != string::npos)			
		{
			cout << "���� ������ �����Դϴ�. "<<endl;
			continue;
		}
		int pos = prob.find(c);
		if (pos == string::npos) 
		{
			cout << "������ ���ڰ� �����ϴ�." << endl;
			tries++;
			continue;
		}
		else 
		{
			answer[pos] = c;
			pos = prob.find(c, pos + 1);   //���� ���ڰ� �� ������ �ݺ������� ã��
			while (pos != string::npos)
			{
				answer[pos] = c;
				pos = prob.find(c, pos + 1);
			}
		}
		cout << "���� ����: " << answer << endl;
		if (answer == prob)
		{
			cout << "�¾ҽ��ϴ�!" << endl;
			break;
		}
	}
	if(tries >= maxnum)
	{
		cout << "Ʋ�Ƚ��ϴ�. ������ [" << prob << "] �Դϴ�." << endl;
	}

	return 0;

}