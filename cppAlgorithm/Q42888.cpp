// ����ä�ù�: https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string commands[3] = { "Enter", "Leave", "Change" };

    //id, name�� dictionary
    map<string, string> idMap;
    map<string, string>::iterator p;

    //record���� �߶� �־��� commend, uid, name
    string command; string uid; string name;

    //�� record�� ���� id:name�� dictionary ����
    for (string a : record)
    {
        stringstream ss(a); ss >> command; ss >> uid;
        if (command == commands[0] || command == commands[2])
        {
            ss >> name;
            idMap[uid] = name;
        }
    }

    //�� record�� ó��
    for (string a : record)
    {
        stringstream ss(a); ss >> command; ss >> uid;
        if (command == commands[0]) answer.push_back(idMap[uid] + "���� ���Խ��ϴ�.");
        else if (command == commands[1]) answer.push_back(idMap[uid] + "���� �������ϴ�.");
    }

    return answer;
}