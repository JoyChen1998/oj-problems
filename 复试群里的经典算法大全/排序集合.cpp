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


int arr[10] = {1,5,4,6,2,3,10,8,9,0};


//冒泡排序
void bubSort(int a[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1 ; j++) {
            if(a[j] > a[j+1]) swap(a[j], a[j+1]);
        }
    }


    cout<<"select Sort finished "<<endl;
    for(int i = 0; i< n; i++)
        cout<<a[i]<<" ";
    cout<<endl;


}

//选择排序
void selectSort(int a[], int n) {
    int minn = 0x3f3f3f, minnpos = 0;
    for(int i = 0; i < n-1; i++) {
        minnpos = i;
        for(int j = i; j < n; j++) {
            if(a[minnpos] > a[j]) {
                minnpos = j;
            }
        }
        cout<<a[i]<<" with "<<a[minnpos]<<" swap"<<endl;
        if(i != minnpos)
            swap(a[i], a[minnpos]);
        for(int x = 0; x < n; x++)
            cout<<a[x]<<" ";
        cout<<endl;
    }

    cout<<"select Sort finished "<<endl;
    for(int i = 0; i< n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

}


// 插入排序
void insort(int number[],int n) {
    int i, j, k, tmp;
    for(j = 1; j < n; j++) {
        tmp = number[j];
        i = j - 1;
        while (tmp < number[i]) {
            number[i + 1] = number[i];
            i--;
            if (i == -1)
                break;
        }
        number[i + 1] = tmp;
        printf("第 %d 次排序:", j);
        for (k = 0; k < n; k++)
            printf("%d ", number[k]);
        printf("\n");
    }


}

int part(int a[], int s , int e) {
    int half = (s + e) /2 ;
    int p = a[s];
    int i =s, j = e;
    while(i < j) {
        while (i < j && a[j] >= p) j--;
        a[i] = a[j];
        while(i < j && a[i] <= p) i++;
        a[j] = a[i];
    }
    a[i] = p;
    return i;
}

void quickSort(int a[], int s, int e) {
    if(s < e ) {
        int pivot = part(a, s, e) ;
        quickSort(a, s, pivot-1);
        quickSort(a, pivot+1 ,e);
    }

}


int main() {

//    selectSort(arr, 10);

//    insort(arr ,10);
    quickSort(arr, 0 , 9);
    for(int i =0 ; i < 10; i++) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
