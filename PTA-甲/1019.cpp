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

int main(){
    int n,d;
    cin>>n>>d;
    vector<int> v;
    if(n==0) v.push_back(0);
    while(n){
        v.push_back(n%d);
        n/=d;
    }
    vector<int> vr(v.rbegin(),v.rend());
    if(vr==v) cout<<"Yes"<<endl;
    else  cout<<"No"<<endl;
    int len = vr.size();
    for(int i=0;i<len;++i){
        if(i!=0) cout<<' ';
        cout<<vr[i];
    }
    return 0;
}