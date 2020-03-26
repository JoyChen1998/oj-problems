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

//1 hanoi ,  柱子为ABC, 从A -> C, 上面的小于下面的盘子


void hanoi(int n, char a, char b, char c) {
    if(n == 1)  // 只剩下1个盘子时，就直接将其从`A`移到`C`
        printf("move plate %d from %c to %c\n", n ,a ,c);
    else {
        hanoi(n-1, a, c, b);    // 否则将其从`A`先放到`B`
        printf("move plate %d from %c to %c\n", n ,a ,c);
        hanoi(n-1, b, a, c);    // 再将其从`B`移动到`C`
    }
}


int main()
{
    int n; // 盘子数量
    cin>>n;
    hanoi(n, 'A', 'B', 'C');

    return 0;
}