#include <iostream>
using namespace std;
#define ST_NUM 20				// C 스타일
const int StudentNumber = 20;	// C++ 스타일
void main()
{
	// TODO: ST_NUM 명의 성적 평균 구하기
	int scores[ST_NUM];
	for (int st = 0; st < StudentNumber; st++)
	{
		cout << st + 1 << "번째 학생 성적을 입력하세요: ";
		cin >> scores[st];
	}
	int sum = 0;
	for (int i = 0; i < ST_NUM; i++) sum += scores[i];
	double average = (double) sum / ST_NUM;
	cout << "SUM = " << sum << endl;
	cout << "AVERAGE = " << average << endl;
}