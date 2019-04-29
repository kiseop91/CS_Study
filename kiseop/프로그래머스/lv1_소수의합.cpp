#include <memory.h>
#include <vector>
#include <math.h>
using namespace std;
const int MAX = 10000000;
bool isPrime[MAX + 1];

void eratos(int n)
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = (int)sqrt(n);

	for (int i = 2; i <= sqrtn; ++i)
	{
		if (isPrime[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
}
long long solution(int N) {
    long long answer = 0;
    eratos(N);
    for(int i=2;i<=N; i++){
        if(isPrime[i])
            answer+=i;
    }
    return answer;
}