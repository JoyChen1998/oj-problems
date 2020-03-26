//完全背包
#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int solve(int w[], int v[], int n , int W) {
    int dp[n][W+1];
    for(int i = 0; i <= W; i++){
        dp[0][i] = i / w[0] * v[0];
    }
    for(int i = 0; i < n; i++){
        dp[i][0] = 0;
    }
    int max = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= W; j++){
            for(int k = 0; k * w[i] <= j; k++){
                int t = k * v[i] + dp[i - 1][j - k * w[i]];
                if(max < t){
                    max = t;
                }
            }
            dp[i][j] = max;
            //特别要注意max要重置为零,否则dp数组里面的值是错误的
            max = 0;
        }
    }
    return dp[n - 1][W];
}

int main()
{
    int n;
    cin>>n;
    int w[n];
    int v[n];
    for(int i =0;i < n; i++)
        cin>>w[i];
    for(int i =0 ; i < n; i++)
        cin>>v[i];

    int W;
    cin>>W;
    int res = solve(w,v,n, W);
    cout<<res<<endl;
    return 0;

}