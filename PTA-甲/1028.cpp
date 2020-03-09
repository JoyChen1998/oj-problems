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

struct stu {
    string id , name ;
    int score;
};
bool cmp1(stu a, stu b) {
    return a.id < b.id;
}

bool cmp2(stu a, stu b) {
    return a.name < b.name;
}

bool cmp3(stu a, stu b) {
    return a.score < b.score;
}
int main(){
    int n,c;
    cin>>n>>c;
    stu s[n];
    for(int i = 0 ; i < n ; i++) {
        cin>>s[i].id>>s[i].name>>s[i].score;
    }

    if(c == 1) {
        sort(s, s+n, cmp1);
    } else if(c == 2) {
        sort(s, s+n, cmp1);
        sort(s, s+n, cmp2);
    } else if(c == 3){
        sort(s, s+n, cmp1);
        sort(s, s+n, cmp3);
    }

    for(int i = 0; i < n ; i++) {
        cout<<s[i].id<<" "<<s[i].name<<" "<<s[i].score<<endl;
    }
    return 0;
}
