// 오픈채팅방: https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string commands[3] = { "Enter", "Leave", "Change" };

    //id, name의 dictionary
    map<string, string> idMap;
    map<string, string>::iterator p;

    //record에서 잘라 넣어줄 commend, uid, name
    string command; string uid; string name;

    //각 record에 대해 id:name의 dictionary 구성
    for (string a : record)
    {
        stringstream ss(a); ss >> command; ss >> uid;
        if (command == commands[0] || command == commands[2])
        {
            ss >> name;
            idMap[uid] = name;
        }
    }

    //각 record의 처리
    for (string a : record)
    {
        stringstream ss(a); ss >> command; ss >> uid;
        if (command == commands[0]) answer.push_back(idMap[uid] + "님이 들어왔습니다.");
        else if (command == commands[1]) answer.push_back(idMap[uid] + "님이 나갔습니다.");
    }

    return answer;
}