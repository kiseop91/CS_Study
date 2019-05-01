#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    if(s[0]>='a' && s[0]<='z')
        s[0] = s[0] -('a'-'A');
    
    for(int i =1; i<s.length(); i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i] = s[i] +('a'-'A');
    
    for(int i =0; i<s.length(); i++){
        if(s[i] == ' '){
            if(s[i+1]==' ')
                continue;
            if(s[i+1]>='a' && s[i+1]<='z')
                s[i+1] = s[i+1] -('a'-'A');
        }
    }
    answer = s;
    return answer;
}