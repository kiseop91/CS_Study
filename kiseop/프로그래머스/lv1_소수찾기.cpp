#include <string>
#include <vector>
#include <math.h>
#include <memory.h>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX + 1];

void eratos(int n)
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0]=isPrime[1]=false;
    int nsqrt = (int)sqrt(n);
    for(int i=2; i<=nsqrt; ++i)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<=n; j+=i)
                isPrime[j]=false;
        }
    }
}
int solution(int n) {
    int answer = 0;
    eratos(n);
    for(int i=0; i<=n; ++i)
    {
        if(isPrime[i])
            answer++;
    }
    return answer;
}