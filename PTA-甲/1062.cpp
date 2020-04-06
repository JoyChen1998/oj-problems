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
typedef long long ll;

//
// a+b 若a，b都为+ ，和为-，则上溢出，一定>c ;
//     若a，b都为-， 和为+，则下溢出，一定<c ;
//

int main() {
    ll a, b, c;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        ll d = a + b;
        if (a > 0 && b > 0) {
            if (d < 0)
                printf("Case #%d: true\n", i + 1);
            else if (d > c) {
                printf("Case #%d: true\n", i + 1);
            }
            else {
                printf("Case #%d: false\n", i + 1);
            }
        }
        else if (a < 0 && b < 0) {
            if (d >= 0)
                printf("Case #%d: false\n", i + 1);
            else if (d > c) {
                printf("Case #%d: true\n", i + 1);
            }
            else {
                printf("Case #%d: false\n", i + 1);
            }
        }
        else {
            if (d > c) {
                printf("Case #%d: true\n", i + 1);
            }
            else {
                printf("Case #%d: false\n", i + 1);
            }
        }
    }
    return 0;
}