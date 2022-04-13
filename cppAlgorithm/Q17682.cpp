// [2018 카카오] 다트게임: https://programmers.co.kr/learn/courses/30/lessons/17682
#include <string>
#include <regex>
#include <vector>
using namespace std;

int solution(string dartResult) {
    //정규표현식 만들기
    regex r("([0-9]{1,2})([SDT]{1})([\x23\x2A]?)");
    regex r1("[0-9]{1,2}"); regex r2("[SDT]{1}");

    //회차별 점수와 옵션을 담을 벡터
    vector<int> scores(3);
    vector<string> options(3);

    //정규표현식에 따른 분리
    sregex_iterator itr; int i = 0;
    auto begin = sregex_iterator(dartResult.begin(), dartResult.end(), r);
    auto end = sregex_iterator();
    for (itr = begin; itr != end; ++itr)
    {
        smatch mat = *itr;
        smatch mat1 = *sregex_iterator(mat.str().begin(), mat.str().end(), r1);
        scores[i] = stoi(mat1.str());
        smatch mat2 = *sregex_iterator(mat.str().begin(), mat.str().end(), r2);
        options[i] = mat2.suffix().str()[0];

        if (mat2.str() == "D") scores[i] *= scores[i];
        else if (mat2.str() == "T") scores[i] *= scores[i] * scores[i];

        i++;
    }

    //옵션에 따른 계산
    for (i = 0; i < options.size(); i++)
    {
        if (options[i] == "*")
        {
            if (i == 0) scores[i] *= 2;
            else
            {
                scores[i] *= 2;
                scores[i - 1] *= 2;
            }
        }
        else if (options[i] == "#") scores[i] *= -1;
    }

    return scores[0] + scores[1] + scores[2];
}