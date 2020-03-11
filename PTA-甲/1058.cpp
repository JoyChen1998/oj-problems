#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
     int g1,s1,k1, g2,s2,k2;
     scanf("%d.%d.%d %d.%d.%d", &g1,&s1,&k1, &g2,&s2,&k2);
     int sum1=0, sum2=0, sum3=0;
     sum1 = g1+g2;
     sum2 = s1+s2;
     sum3 = k1+k2;
     int tmp1 =0, tmp2= 0, tmp3 = 0;
     if(sum3 >= 29) {
         tmp3 = sum3 / 29;
         sum3 -= tmp3 * 29;
     }
     sum2 += tmp3;
     if(sum2 >= 17) {
         tmp2 = sum2 / 17;
         sum2 -= tmp2 * 17;
     }
     sum1 += tmp2;
     cout<<sum1<<"."<<sum2<<"."<<sum3;
    return 0;
}