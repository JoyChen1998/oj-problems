#include<iostream>
#include<cstdio>
using namespace std;
long int n, num, den, a, b;
int gcd(long int a, long int b) {
	return b == 0 ? a : gcd(b, a % b); 
}
int main() {
	scanf("%d", &n);
	scanf("%ld/%ld", &num, &den);
	int d = gcd(num, den);
	num /= d; den /= d;
	for(int i = 1; i < n; ++i) {
		scanf("%ld/%ld", &a, &b);
		num = b * num + den * a;
		den *= b;
		int d = gcd(num, den);
		num /= d;
		den /= d;
	} 
	if(num % den == 0) printf("%ld", num / den);
	if(num % den && num / den) printf("%ld ", num / den);
	num %= den; // 分母是负数的情况。
	if(den < 0) {	den  = - den; num = - num;}
	if(num) printf("%ld/%ld", num, den);
	return 0;
} 这月中旬出成绩和复试