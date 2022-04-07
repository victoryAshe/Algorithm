// ������: https://programmers.co.kr/learn/courses/30/lessons/42587
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> pr, int location) {
    int answer = 1, i;
    vector<int> printer;
    for (i = 0; i < pr.size(); i++) printer.push_back(i);
    while (pr.size() > 1)
    {
        if (pr[0] < *max_element(pr.begin() + 1, pr.end()))
        {
            pr.push_back(pr[0]); pr.erase(pr.begin());
            printer.push_back(printer[0]); printer.erase(printer.begin());
        }
        else
        {
            if (printer[0] == location) return answer;
            pr.erase(pr.begin()); printer.erase(printer.begin());
            answer++;
        }
    }
    return answer;
}
/*
* 
* [�ٸ� ��� Ǯ��]: Queue ���
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> printer; vector<int> sorted; //printer: queue�� index ����. sorted: ���ĵ� ��� �����
    for(int i=0; i<priorities.size(); i++) printer.push(i);
    
    while(!printer.empty()) {
        int now_index = printer.front();
        printer.pop();
        if(priorities[now_index] != *max_element(priorities.begin(),priorities.end())) 
            printer.push(now_index); //�ƴѰ�� push
        else {
            sorted.push_back(now_index); priorities[now_index] = 0; //�´°��
        }
    }
    for(int i=0; i<sorted.size(); i++) if(sorted[i] == location) return i+1; 
}

*/