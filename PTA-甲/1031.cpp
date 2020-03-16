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
int main()
{
        char str[81], *p, *q;
        int n1, n2, count;
        int i, j;

        scanf("%s", str);

        count = strlen(str) + 2;
        p = str;
        q = str + (count - 2 - 1);
        n1 = count / 3;
        n2 = count / 3 + count % 3;
        for (i = 0; i < n1 - 1; i++) {
                printf("%c", *p);
                p++;
                for (j = 1; j < n2 - 1; j++)
                        printf(" ");
                printf("%c\n", *q);
                q--;
        }
        for (p; p <= q; p++)
                printf("%c", *p);

        return 0;
}