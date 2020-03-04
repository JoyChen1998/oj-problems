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
    long long a ,b ;
    cin>>a>>b;
    long long sum = a + b;
    string s = to_string(sum);
    int m = sum < 0 ? 1 : 0;
    for(int i = (int)s.length()-3 ;  i > m; i-=3)
        s.insert(i, ",");
    cout<<s<<endl;
    return 0;
}