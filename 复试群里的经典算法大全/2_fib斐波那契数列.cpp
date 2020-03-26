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

// 2. 斐波那契数列, 没啥好说的 => f(n) = f(n-1) + f(n-2) , f(0) = f(1) = 1,

#define N 20

int main()
{
    int fib[N] = {0};
    fib[0] = fib[1] =1;
    for(int i = 2 ; i < N ; i++)
        fib[i] = fib[i-1] + fib[i-2];
    for(int i = 0; i < N; i++)
        printf("fib[%d] = %d\n", i, fib[i]);
    return 0;
}