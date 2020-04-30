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
const int N  = 1005;
int arr1[N], arr2[N], arr3[N];
int main() {
    string s1;
    string s2;
    cin>>s1>>s2;
    stack<int> s;
    int len1 = (int)s1.length(), len2 = (int)s2.length();
    int remain = 0, jinwei = 0;
    for(int i = len1-1 , j =0; i>= 0; i--)
        arr1[j++] = s1[i] - '0';
    for(int i = len2-1 , j =0; i>= 0; i--)
        arr2[j++] = s2[i] - '0';
    for(int i = 0 ; i< len1; i++)
        for(int j = 0;j < len2; j++) {   // 将需要求和的部分算在一起 ， 关键！
            arr3[i + j] += arr1[i] * arr2[j];
        }
    for(int i = 0; i <= len1+len2 - 2; i++) {
        remain = (arr3[i] + jinwei ) % 10;
        jinwei = (arr3[i] + jinwei ) / 10;
        s.push(remain);
    }
    while(!s.empty()) {
        cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}