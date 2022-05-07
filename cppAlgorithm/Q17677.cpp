// 2018 카카오_[1차] 뉴스 클러스터링: https://programmers.co.kr/learn/courses/30/lessons/17677
// [Idea] A∪B = A + B - A∩B
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> makeSet(string s)
{
    vector<string> set;
    int i, j; string elem;
    for (i = 0; i < s.length(); i++) if (islower(s[i])) s[i] -= 32;
    for (i = 0; i < s.length() - 1; i++)
    {
        if (isalpha(s[i]) && isalpha(s[i + 1]))
            elem = s.substr(i, 2);
        else continue;
        set.push_back(elem);
    }
    return set;
}

int solution(string str1, string str2) {
    int answer = 0; int i, j;
    vector<string> a = makeSet(str1), b = makeSet(str2);
    if (a.size() == 0 && b.size() == 0) return 65536;

    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    vector<string> uniqueA = a;
    uniqueA.erase(unique(uniqueA.begin(), uniqueA.end()), uniqueA.end());

    float inter = 0;                        // 교집합의 원소 갯수
    float unions = a.size() + b.size();     // 합집합 + 교집합의 원소 갯수
    for (i = 0; i < uniqueA.size(); i++)
    {
        if (find(b.begin(), b.end(), uniqueA[i]) != b.end())
        {
            int countA = count(a.begin(), a.end(), uniqueA[i]);
            int countB = count(b.begin(), b.end(), uniqueA[i]);
            inter += countA < countB ? countA : countB;
            b.erase(find(b.begin(), b.end(), uniqueA[i]), find(b.begin(), b.end(), uniqueA[i]) + countB);
        }
    }
    unions -= inter;                    // A∪B = A + B - A∩B;

    answer = floor((inter / unions) * 65536);
    return answer;
}


/*
* 실패한 풀이!
* [Idea]: A∪B = A + (B - A ∩B)
* 1. A,B집합을 구한 뒤, A의 중복된 원소를 제거한 uniqueA를 생성
* 2. uniqueA를 돌기
    2-1. B에 포함되어있지 않은 원소: unions를 ++
*   2-2. B에 포함되어있는 원소: A에 포함된 수와 B에 포함된 수를 세어 그 중 적은 것을 inter에, 큰 것을 unions에 더하고 B에서 해당 원소들 삭제
* 3. unions += B.size() (∵ B에는 교집합을 제거한 원소만 남아있음)
*
* 테스트케이스 7,9,10,11에서 실패하다가,
* [Idea] A∪B = A+B - A∩B 를 적용해 성공 (실패한 아이디어와 공식은 같으나, 그 과정이 달랐음)
* 실패하는 테스트 케이스를 만들어서 적용해보지는 못했으나, 아마도 2-1에서 로직이 틀린 것 같다.
*/
/*
vector<string> makeSet(string s)
{
    vector<string> set;
    int i, j; string elem;
    for (i = 0; i < s.length(); i++) if (islower(s[i])) s[i] -= 32;
    for (i = 0; i < s.length() - 1; i++)
    {
        if (isalpha(s[i]) && isalpha(s[i + 1]))
            elem = s.substr(i, 2);
        else continue;
        set.push_back(elem);
    }
    return set;
}

int solution(string str1, string str2) {
    int answer = 0; int i, j;
    vector<string> a = makeSet(str1), b = makeSet(str2);
    if (a.size() == 0 && b.size() == 0) return 65536;

    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    vector<string> uniqueA = a;
    uniqueA.erase(unique(uniqueA.begin(), uniqueA.end()), uniqueA.end());

    float inter = 0, unions = 0; // 교집합, 합집합의 원소 갯수
    for (i = 0; i < uniqueA.size(); i++)
    {
        if (find(b.begin(), b.end(), uniqueA[i]) == b.end())
            unions++;
        else
        {
            int min = count(a.begin(), a.end(), uniqueA[i]);
            int max = count(b.begin(), b.end(), uniqueA[i]);
            inter += min < max ? min : max;
            unions += min < max ? max : min;
            b.erase(find(b.begin(), b.end(), uniqueA[i]), find(b.begin(), b.end(), uniqueA[i]) + max);
        }
    }
    unions += b.size();

    answer = floor((inter / unions) * 65536);
    return answer;
}
*/