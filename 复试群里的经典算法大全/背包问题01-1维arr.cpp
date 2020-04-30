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
	1维解法 与 2维不同， 在遍历容量时，需要反向进行遍历` <----` 
	这样不会使用到被覆盖的i-1次的状态
	
	遍历到当前能放下第i个物品的容量为止，否则 j-v[i] < 0

*/
int main() {
	cin>>n>>m;
	for(int i=0;i < n ; i++) cin >>v[i]>>w[i];
	for(int i=0; i < n; i++) 
		for(int j = m; j >=v[i] ;j--)
			f[j] = max(f[j], f[j-v[i]] + w[i]);
	cout<<f[m]<<endl;
	return 0;
}