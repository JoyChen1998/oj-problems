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

int main()
{
    int n;
    cin>>n;
    int mind = 150000 , maxd = 0;
    string minn, maxn;
    for(int i = 0 ; i < n ; i++){
        string name, ind, outd;
        cin>>name>>ind>>outd;
        split(ind, ":", v);
        int indate = stoi(v[0])*3600 + stoi(v[1])*60 + stoi(v[2]);
        split(outd, ":", v);
        int outdate = stoi(v[0])*3600 + stoi(v[1])*60 + stoi(v[2]);
        if(mind > indate) {
            mind = indate;
            minn = name;
        }
        if(maxd < outdate) {
            maxd = outdate;
            maxn = name;
        }
    }

    cout<<minn<<" "<<maxn<<endl;
    return 0;
}