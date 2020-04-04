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

set<char> ss;

int main()
{
    string s, s1 ,s2 ;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0 ; i < (int)s2.size(); i++) {
        ss.insert(s2[i]);
    }

    for(int i = 0 ; i < (int)s1.size(); i++) {
        if(ss.find(s1[i]) == ss.end())
            cout<<s1[i];
    }

    return 0;
}
