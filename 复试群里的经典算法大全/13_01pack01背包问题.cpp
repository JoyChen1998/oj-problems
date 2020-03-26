#include <iostream>
#include <cstring>
using namespace std;

const int N=150;

int v[N]={0,12,8,9,5};
int w[N]={0,15,10,12,8};
int x[N];
int m[N][N];
int c=30;
int n=4;
void traceback()
{
    for(int i=n;i>1;i--)
    {
        if(m[i][c]==m[i-1][c])
            x[i]=0;
        else
        {
            x[i]=1;
            c-=w[i];
        }
    }
    x[1]=(m[1][c]>0)?1:0;
}

int main()
{


    memset(m,0,sizeof(m));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
        {
            if(j>=w[i])
                m[i][j]=max(m[i-1][j],m[i-1][j-w[i]]+v[i]);

            else
                m[i][j]=m[i-1][j];
        }
    }/*
    for(int i=1;i<=6;i++)
    {
        for(int j=1;j<=c;j++)
        {
            cout<<m[i][j]<<' ';
        }
        cout<<endl;
    }
*/
    traceback();
    for(int i=1;i<=n;i++)
        cout<<x[i];
    return 0;
}