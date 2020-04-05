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

int coin[100005];
int n = 0, k = 0;
void pay(int i,int j)
{
    while(i<j){
        //不能直接二重循环，否则会TLE
        int va=coin[i]+coin[j];
        if(va==k){
            printf("%d %d",coin[i],coin[j]);
            exit(0);
        }
        else if(va<k) ++i;
        else --j;
    }
}

int main() {

    scanf("%d %d", &n, &k);
    int  cnt = 0;
    for(int i = 0; i<n ; i++){
        int tmp;
        scanf("%d", &tmp);
        if(tmp < k) coin[cnt++] = tmp;
    }
    sort(coin, coin+cnt);

    pay(0, cnt-1);
    printf("No Solution\n");
    return 0;
}