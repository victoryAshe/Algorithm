// 프로그래머스 게임프로그래머 데브매치 챌린지 01: 못풀었음(...
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> p) {
    vector<int> answer(5);
    vector<int> classes = { 10000,20000,50000,100000 };
    vector<int> month31 = { 1, 3, 5, 7, 8, 10, 12 };
    vector<int> month30 = { 4, 6, 9, 11 };

    int i, j, day;
    vector<int> date; vector<int> money;

    for (string a : p)
    {
        day = stoi(a.substr(8, 2));
        int month = stoi(a.substr(5, 2));
        for (i = 1; i < month; i++)
        {
            if (find(month31.begin(), month31.end(), i) != month31.end())
                day += 31;
            else if (find(month30.begin(), month30.end(), i) != month30.end())
                day += 30;
            else day += 28;
        }

        date.push_back(day); money.push_back(stoi(a.substr(11)));

        cout << day << ": " << a.substr(11) << endl;
    }


    if (date[0] > 1) answer[0] = date[0] - 1;
    answer[0] += 335 - (date[date.size() - 1] - 1);
    //TODO: 날짜별 구매액에 따라 각 등급의 지속일을 계산
    int m;
    for (i = 0; i < date.size(); i++)
    {
        day = 0;
        m = money[i];
        if (m < classes[0]) answer[0] += date[i + 1] - date[i];
        for (j = i + 1; j < date.size(); j++)
        {
            if (date[j] < date[i] + 30)
            {
                m += money[j];
                if (j == date.size() - 1) day = date[j] - date[i];
            }
            else
            {
                day = date[j - 1] - date[i];
                if (day == 0) day = 30;
                cout << date[i] << "부터" << date[j - 1] << "까지 구매액: " << m << endl;
                break;
            }
        }

        if (m < classes[0]) answer[0] += day;
        else if (m < classes[1]) answer[1] += day;
        else if (m < classes[2]) answer[2] += day;
        else if (m < classes[3]) answer[3] += day;
        else answer[4] += day;

    }

    for(i=0;i<isclass.size();i++)
    {

    }


    return answer;
}