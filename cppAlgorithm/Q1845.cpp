// 폰켓몬: https://programmers.co.kr/learn/courses/30/lessons/1845
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    /*[Idea]
    * 1. nums.size()/2를 구함
    * 2. nums에 같은 요소가 있으면 삭제
    * 3. return nums.size/2 < 남은 요소수 ? nums.size/2 : 남은 요소 수
    */
    int answer = (int) nums.size() / 2, i;
    //중복 제거
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    //값 반환
    return answer < nums.size() ? answer : nums.size();
}