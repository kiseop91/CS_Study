#include <cstdio>
using namespace std;
long long a, b, c;
long long power(long long a, long long b, long long c) {
    long long ret = 1LL;
    while (b > 0) {
        if (b % 2 == 1) {
            ret *= a;
            ret %= c;
        }
        a *= (a%c);
        a %= c;
        b /= 2;
    }
    return ret % c;
}
int main() {
{
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld\n", power(a, b, c));
    
    return 0;
}