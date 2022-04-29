// 소수 찾기: https://programmers.co.kr/learn/courses/30/lessons/42839
// 순열을 완전탐색해주는 함수 algorithm::next_permutation(a.begin(),a.end()): https://codingwell.tistory.com/33
//  * 위 함수를 사용하려면 타겟 vector/string이 오름차순으로 정렬되어있어야한다.
#include <string>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n == 0 || n == 1) return false;
    int i;
    for (i = 2; i <= sqrt(n); i++) 
        if (n % i == 0)return false;
    return true;
}

int solution(string numbers) {

    unordered_set<int> prime;
    int x = 0;
    int i;
    sort(numbers.begin(), numbers.end());
    do
    {
        for (i = 1; i < numbers.size() + 1; i++)
        {
            x = stoi(numbers.substr(0, i));
            if (isPrime(x)) prime.insert(x);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return prime.size();

}


//다른 풀이: 에라토스테네스의 체 이용
#include <set>
int solution2(string numbers)
{
    sort(numbers.begin(), numbers.end());
    int max = stoi(numbers);
    int answer = 0;
    bool * prime = new bool[max];
    *prime = { false, };
    for (int i = 2; i <= max; i++)
    {
        if (prime[i]) continue;
        for (int j = i + i; j <= max; j += i)
            prime[j] = true;
    }
    
   
    return answer;
}