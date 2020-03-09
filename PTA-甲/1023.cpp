#include <iostream>
#include <string>
using namespace std;
int arr[10];
string doub(string s);
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        arr[s[i] - '0']++;
    }
    string rs = doub(s);
    for (int i = 0; i < rs.size(); ++i) {
        arr[rs[i] - '0']--;
    }
    bool f = 1;
    for (int i = 0; i < 10; ++i) {
        if (arr[i] != 0) f = 0;
    }
    if (f)cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << rs << endl;
    system("pause");
    return 0;
}
string doub(string s) {
    string ss(s.rbegin(), s.rend());
    int x,cur=0;
    for (int i = 0; i <ss.size() ; ++i) {
        x = ss[i] - '0';
        x = (x) * 2+cur;
        ss[i] = (x % 10)+'0';
        cur = (x)/10;
    }
    while (cur) {
        ss += (cur % 10) + '0';
        cur /= 10;
    }
    string str(ss.rbegin(), ss.rend());
    return str;
}