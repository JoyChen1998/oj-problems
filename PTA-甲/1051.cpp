#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector> 
#include<string>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;


int n, m, k;

int main() {
    cin >> m >> n >> k;
    //m 栈容量;
    //n 压栈元素个数；
    for (int i = 0; i < k; i++) {
        stack<int>st;
        vector<int>seq(n);
        for (int j = 0; j < n; j++) {
            cin >> seq[j];
        }
        bool flag = true;
        int index = 0;
        for (int i = 1; i <= n; i++) {
            st.push(i);
            if (st.size() > m) {
                flag = false;
                break;
            }
            while (!st.empty()&&st.top() == seq[index]) {
                st.pop();
                index++;
            }
        }
        if (st.empty() && flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}