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

string str = "0123456789ABC";
int main(){
    int n;
    cout<<"#";
    for(int i = 0 ; i < 3 ; i++){
        cin>>n;
        cout<<str[n/13]<<str[n%13];
    }
    return 0;
}
