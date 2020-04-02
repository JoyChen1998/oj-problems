#include <iostream>
#include <cstdlib>
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

int a[750][750];
int main()
{
    int n,x,y,k;

    while(scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        a[0][0]=1;
        k=1;
        x=y=0;
        while(k<n*n)
        {
            while(y+1<n&&a[x][y+1]==0)  a[x][++y]=++k;
            while(x+1<n&&a[x+1][y]==0)  a[++x][y]=++k;
            while(y-1>=0&&a[x][y-1]==0)  a[x][--y]=++k;
            while(x-1>=0&&a[x-1][y]==0)  a[--x][y]=++k;
        }
        for(x=0;x<n;x++)
        {
            for(y=0;y<n-1;y++)
            {
                printf("%d ",a[x][y]);
            }
            printf("%d\n",a[x][y]);
        }

    }
}
