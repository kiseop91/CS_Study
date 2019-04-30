#include <string>
#include <vector>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long sqrtn = (int)sqrt(n);
    if(pow(sqrtn,2)==n)
    {
        answer = pow(sqrtn+1,2);
    }
    else
        return -1;
    return answer;
}