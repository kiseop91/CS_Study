#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int cnt=0;
    for(const auto x : seoul)
    {
        if(x == "Kim")
            break;
        cnt++;
    }
    answer="�輭���� "+to_string(cnt)+"�� �ִ�";
    return answer;
}