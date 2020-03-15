#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector> 
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 1002;
int main() {
    double a[maxn];
    for (int i = 0; i < maxn; i++)
        a[i] = 0.0;
    for (int i = 0; i < 2; i++) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            int n;
            double k;
            scanf("%d %lf", &n, &k);
            a[n] += k;
        }
    }
    //统计；
    int cnt = 0;
    for (int i = 0; i < maxn; i++) {
        if (a[i] != 0.0) {
            cnt++;
        }
    }
    cout << cnt;
    for (int i = maxn - 1; i >= 0; i--) {
        if (a[i] != 0.0) {
            printf(" %d %.1lf", i, a[i]);
        }
    }
    return 0;
}