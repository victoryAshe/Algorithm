// [2021 īī��] �ű� ���̵� ��õ: https://programmers.co.kr/learn/courses/30/lessons/72410
// ��� ��: [string �� Ư�� chr �˻�] strchr(string target, char find) https://blockdmask.tistory.com/389
// ��� ��: |= ����: ��Ʈ OR ����. ex) 'A'|= 32 -> 'a' (65|=32 = 97)
// ��� ��: regex[^x] : x�� �ƴ� ��. 
// regex�� ó���� �� �ڵ尡 �ܼ��������� ó���ð��� �����ɸ���(0.11~0.33ms), �Ʒ��� [�ٸ� ����� Ǯ��]�� Ǯ�� ������ ���� ó���ȴ�(0.01ms).
#include <string>
#include <regex>
using namespace std;

string solution(string id) {
    int i;
    for (i = 0; i < id.size(); i++) if (isupper(id[i])) id[i] = tolower(id[i]);
    id = regex_replace(id, regex("[^a-z\._0-9\-]"), "");
    id = regex_replace(id, regex("[.]{2,}"), ".");
    if (id[0] == '.') id.erase(id.begin()); if (id[id.size() - 1] == '.') id.erase(id.end() - 1);
    if (id == "") id = "a";
    if (id.size() >= 16)
    {
        id = id.substr(0, 15); if (id[id.size() - 1] == '.') id.erase(id.end() - 1);
    }
    while (id.size() < 3) id += id[id.size() - 1];
    return id;
}
/*
* [�ٸ� ��� Ǯ��] 
#include <bits/stdc++.h>
using namespace std;

string solution(string new_id) {
    for (char& ch : new_id) if ('A' <= ch && ch <= 'Z') ch |= 32;

    string ret;
    for (char& ch: new_id) {
        if ('a' <= ch && ch <= 'z' ||
            '0' <= ch && ch <= '9' ||
            strchr("-_.", ch)) ret += ch;
    }

    new_id = ret;
    ret.clear();
    for (char& ch: new_id) {
        if (!ret.empty() && ret.back() == '.' && ch == '.') continue;
        ret += ch;
    }

    if (ret.front() == '.') ret.erase(ret.begin());
    if (ret.back() == '.') ret.pop_back();

    if (ret.empty()) ret = "a";
    if (ret.size() >= 16) ret = ret.substr(0, 15);
    if (ret.back() == '.') ret.pop_back();
    while (ret.size() <= 2) ret += ret.back();

    return ret;
}


*/