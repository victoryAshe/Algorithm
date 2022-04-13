#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string prob = "approximately";
	int length = prob.length();
	int tries = 0, maxnum = 0; 
	string answer(length, '-');		// '-'로 초기화

	cout << "최대 시도 횟수: ";
	cin >> maxnum;
	cout << endl;

	cout << "현재 상태: " << answer << endl;
	while (tries < maxnum && answer != prob)
	{
		cout << endl;
		char c;
		cout << "글자를 추측하시오: ";
		cin >> c;

		//string :: npos는 -1 값의 상수 -> find() 함수에서 못 찾은 경우 return npos
		if(answer.find(c) != string::npos)			
		{
			cout << "전과 동일한 글자입니다. "<<endl;
			continue;
		}
		int pos = prob.find(c);
		if (pos == string::npos) 
		{
			cout << "추측한 글자가 없습니다." << endl;
			tries++;
			continue;
		}
		else 
		{
			answer[pos] = c;
			pos = prob.find(c, pos + 1);   //같은 글자가 또 있으면 반복적으로 찾기
			while (pos != string::npos)
			{
				answer[pos] = c;
				pos = prob.find(c, pos + 1);
			}
		}
		cout << "현재 상태: " << answer << endl;
		if (answer == prob)
		{
			cout << "맞았습니다!" << endl;
			break;
		}
	}
	if(tries >= maxnum)
	{
		cout << "틀렸습니다. 정답은 [" << prob << "] 입니다." << endl;
	}

	return 0;

}