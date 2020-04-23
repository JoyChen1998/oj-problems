#include<iostream>
using namespace std;

int main() {

/* 
！！！！注意这里的条件 -1 <= i < 1 ，这里需要判断2次，第一次是-1 <= i , 然后用其判断结果再 与1 判断。
而不是简单的连等判断

*/
    int a, i;
    for ( a = 1, i = -1;-1<= i <1 ; i++){
        a++;
        cout<<"a="<<a<<endl;
    }
    cout<<"i="<<i<<endl;
    return 0;
}