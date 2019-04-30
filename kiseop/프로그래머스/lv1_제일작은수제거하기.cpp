#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size()==1)
        return vector<int>{-1};
    int min=1999999999;
    for(auto x : arr){
        if(min>x)
            min=x;
    }
    for(auto x : arr){
        if(min!=x)
            answer.push_back(x);
    }
    return answer;
}