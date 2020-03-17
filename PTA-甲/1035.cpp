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


struct stu {
    string id, pass;
    bool mo = false;
};
int main()
{
    int n;
    int sum = 0;
    cin>>n;
    stu s[n];
    for(int i = 0 ;i < n ; i++) {
        string id, pass;
        cin>>id>>pass;
        s[i].id =id;
        for(int j = 0; j < pass.length(); j++) {
            if(pass[j] == '1') {
                s[i].mo = true;
                pass[j] = '@';
            } else if(pass[j] == '0') {
                s[i].mo = true;
                pass[j] = '%';
            } else if(pass[j] == 'l') {
                s[i].mo = true;
                pass[j] = 'L';
            } else if(pass[j] == 'O') {
                s[i].mo = true;
                pass[j] = 'o';
            }
        }
        if(s[i].mo) sum++;
        s[i].pass = pass;
    }
    if(sum > 0) {
        cout<<sum<<endl;
        for(int i =0 ; i < n; i++) {
            if(s[i].mo) {
                cout<<s[i].id<<" "<<s[i].pass<<endl;
            }
        }
    } else if (n == 1 ) cout<<"There is 1 account and no account is modified"<<endl;
        else cout<<"There are "<<n<<" accounts and no account is modified"<<endl;
    return 0;
}