// 최대공약수와 최소공배수: https://programmers.co.kr/learn/courses/30/lessons/12940
// 유클리드 호제법: https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kmc7468&logNo=221017936040
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int a = n, b = m, c;
    while (b != 0) //최대공약수(GCD) 공식
    {
        c = a % b; a = b; b = c;
    }
    answer.push_back(a);
    answer.push_back(n * m / a); //최소공배수(LCM) 공식
    return answer;

    /*
    //다른 사람 풀이: GCD를 재귀의 조건식으로 풀이
    
    int Euclidean(int a, int b)
    {
        return b ? Euclidean(b, a % b) : a;
    }

    vector<int> gcdlcm(int a, int b)
    {
        vector<int> answer;
        
        answer.push_back(Euclidean(a, b));    //GCD
        answer.push_back(a * b / answer[0]);  //LCM

        return answer;
    }
    */
}