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
#define MAX_NUM 10000000

bool isPrime[ MAX_NUM + 10 ];

void prim(){
    for(int i = 2; i <= MAX_NUM; i++)
        isPrime[i] = true;
    for(int i = 2; i <= MAX_NUM; i++){
        if( isPrime[i] )
            for(int j = 2 * i; j <= MAX_NUM; j += i)
                isPrime[j] = false;
    }
}

bool check(int n, int d) {
    int tmp1 = n;
    vector<int> v;
    while (n) {
        v.push_back(n % d);
        n /= d;
    }
    int tmp2 = 0;
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        tmp2 += v[i] * pow((float)d, i);
    }
    return isPrime[tmp1] && isPrime[tmp2];
}

int main()
{
    prim();
    int n = 0, d =0;
    while(true) {
        cin>>n;
        if(n < 0) break;
        cin>>d;
        if(check(n, d)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}