// 2018 카카오_[1차] 뉴스 클러스터링: https://programmers.co.kr/learn/courses/30/lessons/17677
// 아직 못 풀었음
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> makeSet(string s)
{
    vector<string> set;
    int i, p; string elem;
    for (i = 0; p < s.length(); i++)
    {
        if (!isalpha(s[i]))
        {
            p++; continue;
        }
        p = i; elem = "";
        while (elem.length() < 2)
        {

            if (isalpha(s[p]))
            {
                if (s[p] > 90) elem += s[p] - 32;
                else elem += s[p];
            }
            p++;
        }
        set.push_back(elem);
    }

    return set;
}


int solution(string str1, string str2) {
    int answer = 0;
    vector<string> a = makeSet(str1), b = makeSet(str2);
    //sort(a.begin(), a.end()); sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 0; i < b.size(); i++) cout << b[i] << " ";
    cout << endl;

    /*
    int inter = 0; int unions = 0; // 교집합과 합집합의 원소 개수
    int i;
    for (i = 0; i < a.size(); i++)
    {
        if (find(b.begin(), b.end(), a[i]) != b.end())
        {
            b.erase(find(b.begin(), b.end(), a[i]));
            inter++;
        }
        unions++;
    }
    unions += b.size();

    answer = (int)(inter / unions * 65536);
*/
    return answer;
}