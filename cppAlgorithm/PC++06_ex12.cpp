#include <iostream>
#include <cstring>
using namespace std;
void main()
{
	char s[][10] = { "HIGH", "MIDDLE", "LOW" };
	cout << *(s[2]+1) << endl;		// -> 'O' (�� *(s[2])�� s[2]�� ���� �ּҿ� �ִ� L�� ��ȯ.)
}

