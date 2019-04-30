#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp{
  bool operator()(char a, char b){
      return a<b;
  }  
};
string solution(string s) {
    string answer = "";
    priority_queue<char,vector<char>,cmp> pq;

    for(int i = 0; i<s.size(); i++)
    {
        pq.push(s[i]);
    }
    while(!pq.empty())
    {
        answer.push_back(pq.top());
        pq.pop();
}
    return answer;
}