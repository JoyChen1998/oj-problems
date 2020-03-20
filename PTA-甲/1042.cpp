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

//只需要判断交换牌组的次数就好
string cards[55];
string cards_n[55];
int arr[60];
const string prex[4] = {"S", "H", "C", "D"};

int main()
{
    int k = 1;
    for (const auto &i : prex) {
        for(int j = 1 ; j <= 13 ;j ++) {
            cards[k++] = i + to_string(j);
        }
    }
    cards[k++] = "J1";
    cards[k] = "J2";

    int n;
    cin>>n;
    int judge = n;
    for(int i =1 ; i <= 54; i++) {
        cin>>arr[i];
    }
    int cnt = 1;
    while(n--) {
        if(cnt % 2 != 0) {
            for(int i =1 ; i <= 54; i++) {
                cards_n[arr[i]] = cards[i];
            }
        } else {
            for(int i =1 ; i<= 54; i++) {
                cards[arr[i]] = cards_n[i];
            }
        }
        cnt ++;
    }

    if(judge%2==0){
        for(int i= 1 ;i < 54; i++) {
            cout<<cards[i]<<" ";
        }
        cout<<cards[54]<<endl;
    } else {
        for(int i= 1 ;i < 54; i++) {
            cout<<cards_n[i]<<" ";
        }
        cout<<cards_n[54]<<endl;
    }

    return 0;
}