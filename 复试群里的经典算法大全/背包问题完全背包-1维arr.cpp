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
	在遍历容量时，正向遍历通过覆盖的方式，让其放置第i物品时，达到最大
	
	遍历起点为v[i]，否则 j-v[i] < 0

*/
int main() {
	cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>v[i]>>w[i];
	for(int i = 0 ; i < n; i++) 
		for(int j = v[i]; j <=m ; j++) 
			f[j] = max(f[j], f[j - v[i]]+w[i]);
	cout<<f[m]<<endl;
	return 0;
}