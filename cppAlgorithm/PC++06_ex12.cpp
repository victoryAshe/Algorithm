#include <iostream>
#include <cstring>
using namespace std;
void main()
{
	char s[][10] = { "HIGH", "MIDDLE", "LOW" };
	cout << *(s[2]+1) << endl;		// -> 'O' (∵ *(s[2])는 s[2]의 시작 주소에 있는 L을 반환.)
}

