#define _CRT_SECURE_NO_WARNINGS
#define SCF(a) scanf("%d",&a)
#define SCF2(a,b) scanf("%d%d",&a,&b)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define LL long long

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXM = 200005 * 4;

using namespace std;

struct ST {
	int left, right;
	int maxl;
}t[MAXM];

void built(int root, int l, int r) {
	t[root].left = l;
	t[root].right = r;
	if (l == r)return;
	int mid = (l + r) >> 1;
	built(root << 1, l, mid);
	built(root << 1 | 1, 1 + mid, r);
}

void Fix(int root, int left, int right, int val) {
	if (left <= t[root].left&&t[root].right <= right) {
		t[root].maxl = val; return;
	}
	if (left > t[root].right || right < t[root].left)return;
	Fix(root << 1, left, right, val);
	Fix(root << 1 | 1, left, right, val);
	t[root].maxl = max(t[root << 1].maxl , t[root << 1 | 1].maxl);
}

int Query_max(int root, int left, int right) {
	if (left <= t[root].left&&t[root].right <= right) {
		return t[root].maxl;
	}
	if (left > t[root].right || right < t[root].left)
		return 0;
	int s1 = Query_max(root << 1, left, right);
	int s2 = Query_max(root << 1 | 1, left, right);
	return max(s1,s2);
}


int main() {
	freopen("input.txt", "r", stdin);
	int n, m;
	int x;
	char c;
	while (SCF2(n, m) != EOF) {
		memset(t, 0, sizeof(t));
		built(1, 1, n);
		FOR(i, 1, n) {
			SCF(x);
			Fix(1, i, i, x);
		}
		FOR(j, 1, m) {
			getchar();
			c = getchar();
			int a, b;
			SCF2(a, b);
			if (c == 'Q') {
				printf("%d\n", Query_max(1, a, b));
			}
			if (c == 'U') {
				Fix(1, a, a, b);
			}
		}
	}
	return 0;
}