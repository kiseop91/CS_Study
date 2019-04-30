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
    answer="김서방은 "+to_string(cnt)+"에 있다";
    return answer;
}