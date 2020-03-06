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

struct stu {
    string name, ID;
    char gender;
    int score;
};

int main(){
    int n , maxn = -1, minn = 101;
    cin>>n;
    stu s[n];
    string bname , bid, gname, gid;
    for(int i =0 ; i < n ; i++) {
        cin>>s[i].name>>s[i].gender>>s[i].ID>>s[i].score;
        if(s[i].score < minn  && s[i].gender == 'M') {
            bname = s[i].name;
            bid = s[i].ID;
            minn = s[i].score;
        }
        if(s[i].score > maxn  && s[i].gender == 'F') {
            gname = s[i].name;
            gid = s[i].ID;
            maxn = s[i].score;
        }

    }
    int sum = maxn - minn;
    if(maxn == -1) cout<<"Absent"<<endl;
    else cout<<gname<<" "<<gid<<endl;
    if(minn == 101) cout<<"Absent"<<endl;
    else cout<<bname<<" "<<bid<<endl;

    if(maxn != -1 && minn != 101)   cout<<sum<<endl;
    else cout<<"NA"<<endl;
    return 0;

}
