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


const int N= 1010;
int m,n;
int f[N];
int v[N], w[N], s[N];
/*
	多重背包时，需要再来一次循环试探，达到k个物品时达到最大价值。
	k满足的条件: 
	1. k < s[i]  ，第i个物品有k个
	2. k*v[i]时，要小于当前的最大容量ja
	遍历起点为m，到v[i]结束，否则 j-v[i] < 0

*/
int main() {
	cin>>n>>m;
	for(int i= 0 ; i < n; i++) cin>>v[i]>>w[i]>>s[i];
	for(int i= 0;  i < n; i++) 
		for(int j =m ; j >= v[i] ; j--)
			for(int k = 1; k <= s[i] && k*v[i] <= j; k++ )
				f[j] = max(f[j], f[j - k*v[i]]+ k*w[i]);
	cout<<j[m]<<endl;
	return 0;
}