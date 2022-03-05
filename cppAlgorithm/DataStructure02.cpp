// 22-1 자료구조 과제 02: 학점 부여 프로그램
#include <iostream>
using namespace std;

int main()
{
	int math_scores[20] = {75, 60, 88, 100, 54, 70, 85, 80, 95, 10, 20, 40 , 50, 60, 70, 80, 90, 0, 99, 77};
	char grades[20];
	int i, x, size = sizeof(math_scores)/sizeof(int);
	for (i = 0; i< size; i++)
	{
		x = math_scores[i];
		if (x >= 90) grades[i] = 'A';
		else if (x >= 80) grades[i] = 'B';
		else if (x >= 70) grades[i] = 'C';
		else if (x >= 60) grades[i] = 'D';
		else grades[i] = 'F';
	}
	
	for (i = 0; i < size; i++)
	{
		cout << math_scores[i] << " " << grades[i];
		if (i < size - 1) cout << ", ";
	}
		
	return 0;
}