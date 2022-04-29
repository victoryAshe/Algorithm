// 주식 가격: https://programmers.co.kr/learn/courses/30/lessons/42584
#include <vector>
#include <functional>
using namespace std;

struct isFallen : public binary_function<int, int, bool>
{
public:
    bool operator()(const int a, int b) const
    {
        return(a < b);
    }
};

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    int i;


    for (i = 0; i < prices.size() - 1; i++)
    {
        auto iter = find_if(prices.begin() + i, prices.end(), bind2nd(isFallen(), prices[i]));
        if (iter == prices.end())
        {
            answer[i] = prices.size() - 1 - i;
            continue;
        }
        int idx = iter - prices.begin();
        answer[i] = idx - i;
    }


    return answer;
}