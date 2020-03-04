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


int main()
{
    int n, in =0, sum = 0,cnt = 0;
    cin>>n;
    for(int i = 0 ; i < n; i++) {
        cin>>in;
        int tmp = in - cnt;
        cnt = in;
        if(tmp > 0) sum += 6*tmp;
        else if(tmp < 0) sum -= 4*tmp;
        sum+=5;
    }
    cout<<sum;
    return 0;
}