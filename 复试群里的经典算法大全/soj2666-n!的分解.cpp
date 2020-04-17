#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<stack>

using namespace std;
#define MAXN 1000000
typedef long long LL;
bool flag[MAXN + 1];
int prime[MAXN + 1];
int ans[MAXN + 1];
int MAX, num = 0;

void init() {
    LL i, j;
    for (i = 2; i <= MAXN; i++) {
        if (!flag[i]) {
            prime[num++] = (int) i;
            for (j = i * i; j <= MAXN; j = j + i) flag[j] = true;
        }
    }
}

void solve(int n) {
    int i, N;
    for (i = 0; prime[i] <= n && i < num; i++) {
        N = n;
        while (N) {
            ans[i] = ans[i] + N / prime[i];
            N = N / prime[i];
        }
    }
    printf("%d=", n);
    if (ans[0] == 1) 
        printf("2"); 
    else if (ans[0] > 1) 
        printf("2^%d", ans[0]);
    for (i = 1; prime[i] <= n && i < num; i++) {
        if (ans[i] == 1) 
            printf("*%d", prime[i]);
        else if (ans[i] > 1)
            printf("*%d^%d", prime[i], ans[i]);
    }
    printf("\n");
}

int main() {
    int n;
    init();
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        memset(ans, 0, sizeof(ans));
        solve(n);
    }
    return 0;
}