#define _CRT_SECURE_NO_WARNINGS
#define LL long long
#define MEM(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define BUG cout<<"here"<<endl
#define LSC(a) scanf("%lld",&a)
#define SCF(a) scanf("%d",&a)
#define SCF2(a,b) scanf("%d%d",&a,&b)
#define LSC2(a,b) scanf("%lld%lld",&a,&b)
#define INF 0x3f3f3f3f
#define MAXM 100000
#define MAXN 50005

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

LL x, y;
LL p, q;
LL ans, temp;

LL gcd(LL a, LL b) {
	if (b == 0) {
		p = 1;
		q = 0;
		return a;
	}
	else {
		ans = gcd(b, a%b);
		temp = p;
		p = q;
		q = temp-(a/b)*q;
		return ans;
	}
	if (a >= b) {
		LL m, n;
		LL num = gcd(a+b*(-a/b),b);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	while (LSC2(x, y) != EOF) {
		gcd(x, y);
		printf("%lld %lld\n",p,q);
	}
	return 0;
}