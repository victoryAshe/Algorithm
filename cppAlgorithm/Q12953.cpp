// N개의 최소공배수: https://programmers.co.kr/learn/courses/30/lessons/12953
// 여러 수의 최소 공배수를 구하는 방법: https://mathbang.net/204
// -> 소인수 분해를 시행한 뒤, 공통인 소수중 지수가 제일 큰 것들 * 공통이 아닌 모든 소수들.
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool Primes[101];

void Eratos() //에라토스테네스의 체
{
    int i, j;
    for (i = 2; i <= 100; i++) Primes[i] = true;

    for (i = 2; i * i <= 100; i++)
    {
        if (Primes[i])
            for (j = i * i; j <= 100; j += i)
                Primes[j] = false;
    }
}


int solution(vector<int> arr) {
    vector<int> div = arr;
    int max = *max_element(arr.begin(), arr.end()) + 1;
    int i, j;

    int* idx = new int[max];
    for (i = 0; i < max; i++) idx[i] = 0;
    Eratos();
    
    for (i = 0; i < div.size(); i++)
    {
        for (j = 2; j <= max; j++) if (Primes[j])
        {
            int n = 0;
            while (div[i] % j == 0)
            {
                ++n;
                div[i] /= j;
            }
            if (idx[j] < n) idx[j] = n;
        }
    }

    int answer = 1;
    for (i = 0; i < max; i++) if (idx[i] != 0) answer *= idx[i] > 1 ? pow(i, idx[i]) : i;
    return answer;
}