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


vector<string> v;

void split(const string &src, const string &separator, vector<string> &dest) {
    const string &str = src;
    string substring;
    string::size_type start = 0, index;
    dest.clear();
    index = str.find_first_of(separator, start);
    do {
        if (index != string::npos) {
            substring = str.substr(start, index - start);
            dest.push_back(substring);
            start = index + separator.size();
            index = str.find(separator, start);
            if (start == string::npos)
                break;
        }
    } while (index != string::npos);
    substring = str.substr(start);
    dest.push_back(substring);
}


string name(int i){
    switch(i){
        case 0: return "zero";
        case 1: return "one";
        case 2: return "two";
        case 3: return "three";
        case 4: return "four";
        case 5: return "five";
        case 6: return "six";
        case 7: return "seven";
        case 8: return "eight";
        case 9: return "nine";
        default:
            return "zero";
    }
}


int main(){
    string n;
    cin>>n;
    int sum = 0;
    for(int i = 0 ; i < (int)n.length(); i++) {
        sum += n[i]-'0';
    }
    while(sum > 0) {
        int tmp = sum %10;
        v.push_back( name(tmp));
        sum /= 10;
    }
    if(!v.empty()) {
        for(int i = (int)v.size()-1; i > 0; i--) {
            cout<<v[i]<<" ";
        }
        cout<<v[0]<<endl;
    } else cout<<"zero"<<endl;
    return 0;
}