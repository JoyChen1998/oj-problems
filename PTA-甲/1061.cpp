#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;

string week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
    int cnt1 = 0, cnt2 = 0, flag = 0;
    string date;
    int i , j;
    for(i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++) {
        if(s1[i] == s2[j] && s1[i] >='A' && s1[i] <='G' && !flag) {
           int index = s1[i] - 'A';
           date = week[index];
           flag = 1;
        } else if (s1[i] == s2[j] && flag) {
            if(s1[i] >= 'A' && s1[i] <= 'N'){
                cnt1 = s1[i] - 'A' + 10;
                break;
            }
            else if (s1[i] >= '0' && s1[i] <='9') {
                cnt1 = s1[i] - '0';
                break;
            }
        }
    }
    for(i = 0, j = 0; i < s3.size() && j < s4.size(); i++, j++) {
        if(s3[i] == s4[j] && isalpha(s3[i])) {
            cnt2 = i;
            break;
        }
    }
    cout<<date<<" ";
    printf("%02d:%02d\n", cnt1, cnt2);
    return 0;
}