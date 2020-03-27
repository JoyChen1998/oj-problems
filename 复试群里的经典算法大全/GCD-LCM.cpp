#include <stdio.h> #include <stdlib.h>
int main(void) { int m, n, r;
int s;
printf("输入两数:"); scanf("%d %d", &m, &n); s = m * n;
while(n != 0) { r = m % n;
m = n;
n = r; }
printf("GCD:%d\n", m); printf("LCM:%d\n", s/m);
return 0; }