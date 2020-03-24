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


bool check(string s, int m, int n) {
    int cnt = 0;
    for(int i = m, j = n; i < j;) {
        if(s[i] == s[j]) {
            i++;
            j--;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    int maxn = 1;  //单个字符也属于回文串!
    for(int i = 0; i < (int)s.length(); i++) {
        for(int j = i+1; j < (int)s.length(); j++) {
            if(s[i] == s[j] && check(s, i, j)) {
               maxn = max(maxn, j - i + 1);
            }
        }
    }
    cout<<maxn<<endl;
    return 0;
}