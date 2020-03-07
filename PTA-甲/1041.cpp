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



void split(const string &src, const string &separator, vector<string> &dest) {
    const string &str = src;
    string substring;
    string::size_type start = 0, i;
    dest.clear();
    i = str.find_first_of(separator, start);
    do {
        if (i != string::npos) {
            substring = str.substr(start, i - start);
            dest.push_back(substring);
            start = i + separator.size();
            i = str.find(separator, start);
            if (start == string::npos)
                break;
        }
    } while (i != string::npos);
    substring = str.substr(start);
    dest.push_back(substring);
}

int check[100005] = {0};
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++) {
        int tmp ;
        cin>>tmp;
        arr[i] = tmp;
        check[tmp] ++;
    }
    int x;
    for(x = 0 ; x < n; x++) {
        if(check[arr[x]] == 1)  {
            cout<<arr[x]<<endl;
            break;
        }
    }
    if(x == n)  cout<<"None"<<endl;
    return 0;
}
