#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#define ll long long
 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    // start
    int n, num;
    string s;
    cin>>n ;
    for(int x = 0; x < n ; x++) {
 
        cin>>num;
        int arr[10005];
        memset(arr, 0, sizeof(arr));
        cin>>s;
        if(s.size() <= 2){
            if((s[s.size() - 1] - '0') % 2 == 0) {
                cout<<2<<endl;
                continue;
            }else{
                cout<<1<<endl;
                continue;
            }
        }
 
        int odd_j = -1 , even_o = -1;
        int isodd = 0;
        if(s.size() %2 != 0) isodd = 1;  // odd length num
        for(int i = 0; i < s.size() ; i++){
            int tmp = s[i] - '0';
            if((i+1) %2 == 0 && tmp % 2 == 0) even_o = 1;   // breach has a even num
            if((i+1) %2 != 0 && tmp % 2 != 0) odd_j = 1;
        }

        // judge
        if(isodd == 1) {
            if(odd_j == 1) cout<<1<<endl;
            else if(odd_j == -1) cout<<2<<endl;
        } else {
            if(even_o == 1) cout<<2<<endl;
            else if(even_o == -1) cout<<1<<endl;
        }
    }
    // end
    return 0;
}