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
inline int deal(char *s);
vector<int> student[180000];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int idex, amountpeople;
    char str[10];
    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &idex, &amountpeople);
        for (int i = 0; i < amountpeople; ++i) {
            scanf("%s", str);
            student[deal(str)].push_back(idex);
        }
    }
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        int idex = deal(str);
        sort(student[idex].begin(), student[idex].end());
        printf("%s %d", str, student[idex].size());
        for (int i = 0; i < student[idex].size();++i) {
            printf(" %d", student[idex][i]);
        }
        putchar('\n');
    }
    return 0;
}
int deal(char* s) {
    return (s[0]-'A') * 26 * 26 * 10 + (s[1]-'A') * 26 * 10 + (s[2]-'A') * 10 + s[3];
}