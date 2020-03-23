#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int MAXN = 1e5 + 10;
int sum[MAXN];
int n, m, t = 0x3f3f3f3f;
int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", &sum[i]), sum[i] += sum[i - 1];
	for(int i = 1; i <= n; ++i) {
		int j = upper_bound(sum + i, sum + n + 1, sum[i - 1] + m) - sum;
		if(sum[j - 1] - sum[i - 1] == m) {
			t = m;
			break;
		} else if(j <= n && sum[j] - sum[i - 1] < t) { // 
			t = sum[j] - sum[i - 1];
		}
	}
	for(int i = 1; i <= n; ++i) {
		int j = lower_bound(sum + i, sum + n + 1, sum[i - 1] + t) - sum;
		if(sum[j] - sum[i - 1] == t) printf("%d-%d\n", i, j);
	} 
	return 0;
}