#include <iostream>
#include <cmath>
int arr[100005];
using namespace std;
int main(){
	int n;
	cin >> n;
	int sum = 0, x, y;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		sum += x;
		arr[i] = sum;
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> x >> y;
		int res = abs( arr[y-1] - arr[x-1] );
		int res2 = sum - res;
		if (res < res2) cout << res << endl;
		else cout << res2 << endl;
	}
	system("pause");
	return 0;
}