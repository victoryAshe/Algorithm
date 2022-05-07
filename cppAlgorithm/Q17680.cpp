// 2018 카카오_ [1차] 캐시: https://programmers.co.kr/learn/courses/30/lessons/17680
// LRU_Least Recently Used 알고리즘: https://dailylifeofdeveloper.tistory.com/355
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    int i, j;
    for (i = 0; i < cities.size(); i++)
    {
        string city = "";
        for (j = 0; j < cities[i].length(); j++)
            city += isupper(cities[i][j]) ? cities[i][j] : cities[i][j] - 32;
        if (find(cache.begin(), cache.end(), city) == cache.end())  //cacheMiss
        {
            cache.push_back(city);
            if (cache.size() > cacheSize) cache.erase(cache.begin());
            answer += 5;
        }
        else    //cacheHit
        {
            cache.erase(find(cache.begin(), cache.end(), city));
            cache.push_back(city);
            answer++;
        }
    }

    return answer;
}