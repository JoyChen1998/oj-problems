#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
string add(string a, string b) {
    string ret = "";
    int carry = 0, t = 0;
    for(int i = a.length() - 1; i >= 0; --i) {
        t = a[i] - '0' + b[i] - '0' + carry;
        ret += to_string(t % 10);
        carry = t / 10;
    }
    if(carry) ret += to_string(carry);
    reverse(ret.begin(), ret.end());
    return ret;
}
int main() {
    int k;
    string s;
    cin >> s >> k;
    for(int i = 0; i <= k; ++i) {
        string t = s; reverse(t.begin(), t.end()); 
        if(t == s) {    cout << s << '\n' << i; return 0;   };
        if(i != k) s = add(s, t);
    }
    cout << s << '\n' << k;
    return 0;
}