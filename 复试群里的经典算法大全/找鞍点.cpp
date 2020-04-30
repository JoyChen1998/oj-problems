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
int num = 0;

void init() {  // 素数打表
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
            cout<<"N="<<N<<" N/prime[i]= "<<N/prime[i]<<" i="<<i<<" prime="<<prime[i]<<" ans[i]="<<ans[i]<<endl;
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
    // 找鞍点
    int arr[3][3];
    int cnt = 0;
    int dxpos[3] = {0}, dypos[3] = {0};
    int xxpos[3] = {0}, xypos[3] = {0};
    for(int i=0; i< 3; i++){
        for(int j = 0; j < 3; j++) {
            cin>>arr[i][j];
        }
    }
    int maxn, minn;
    for(int i =0 ;i < 3; i++) {
        maxn = -1;
        for(int j = 0; j< 3 ;j++){
            if(maxn < arr[i][j]) {
                maxn = arr[i][j];
                dxpos[i] = i;
                dypos[i] = j;
            }
        }
    }

    for(int i =0 ;i < 3; i++) {
        minn = 1000000;
        for(int j = 0; j< 3 ;j++){
            if(minn > arr[j][i]) {
                minn = arr[j][i];
                xxpos[i] = j;
                xypos[i] = i;
            }
        }
    }

    for(int i = 0 ; i < 3; i++ ) {
        for(int j = 0; j < 3 ; j++) {
            if(dxpos[i] == xxpos[j] && dypos[i] == xypos[j]) {
                cnt++;
                cout<<dxpos[i]<<" "<<dypos[i]<<" "<<arr[dxpos[i]][dypos[i]]<<endl;
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}