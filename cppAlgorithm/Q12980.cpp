// Summer/Winter Coding(~2018)_ 점프와 순간이동: https://programmers.co.kr/learn/courses/30/lessons/12980
// 2진수로 풀리는 이유: https://programmers.co.kr/questions/13871
//  -> jump를 0으로, 이동을 1로 변환하여 기록한 점프의 기록이 n을 2진수로 변환한 것과 같다.
#include <bitset>
#include <algorithm>
using namespace std;

int solution(int n)
{
    int ans = 0;
    bitset<100>bs(n);
    string s = bs.to_string();
    ans = count(s.begin(), s.end(), '1');
    return ans;
}