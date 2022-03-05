// 22-1 자료구조 과제 01: 성적 평균 계산 프로그램
#include <iostream>
#include <random>
using namespace std;
int main()
{
	// 시드 값을 얻기 위한 random_device 생성
	random_device rd;

	// random_device를통한 난수 생성 엔진 초기화
	mt19937 gen(rd());

	// 균등하게 나타는 난수열 생성을 위한 균등 분포 정의
	uniform_int_distribution<int> dis(0, 100);

	//반/과목/학생
	int scores[3][3][9];
	string subjects[3] = { "수학", "영어", "국어" };
	
	// 점수가 전부 주어지지 않아 난수를 생성했습니다.
	int i, j, k;
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) for (k = 0; k < 9;k++) scores[i][j][k] = dis(gen);

	// 반별 과목별 성적 합
	float sum;
	// 과목별 성적 합
	float sum2[3] = { 0, 0, 0 };

	// 출력되는 float값의 소숫점 자리수를 설정: 1자리까지만 출력
	cout << fixed;
	cout.precision(1);
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = 0;
			for (k = 0; k < 9; k++) sum += scores[i][j][k];
			cout << i + 1 << "반의 " << subjects[j] << " 과목 평균: " << sum / 9 << endl;
			sum2[j] += sum;
		}
		
		cout << endl;
	}
	for (j = 0; j < 3; j++) cout << "3학년의 " << subjects[j] << " 과목 평균: " << sum2[j] / 27 << endl;
		
	

	return 0;
}