#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cmath>
#include <iomanip>
#include <map>
using  namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main(){
    int n,m;
    cin>>n;
    int coupon[n];
    for(int i = 0 ; i < n ; i++)
        cin>>coupon[i];
    cin>>m;
    int product[m];
    for(int i = 0 ; i < m; i++)
        cin>>product[i];
    sort(coupon, coupon+n, cmp);
    sort(product, product+m, cmp);
    int sum = 0;
    int lcp =0 , lpro=0;
    for(int i = 0, j = 0; i < n, j < m;) {
       int val = coupon[i] * product[j];
       if(val > 0 && coupon[i] > 0 && product[i] > 0) {
           sum += val;
           i++;
           j++;
       } else {
           lcp = i;
           lpro = j;
           break;
       }
    }
    for(int i = n-1, j = m-1; i >= lcp , j >= lpro;) { // 坑1，
        int val = coupon[i] * product[j];
        if(val > 0 && coupon[i] < 0 && product[j] < 0) { // 坑2， 因为n,m不一定能匹配上
            sum += val;
            i--;
            j--;
        } else {
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}
