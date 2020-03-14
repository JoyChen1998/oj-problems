
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
class Book {
public:
    string title, author, keyword, publisher, year;
    int id;
    Book(int ID, string a, string b, string c, string d, string e) {
        id = ID; title = a; author = b; keyword = c; publisher = d; year = e;
    }
    Book() {};
    bool operator < (const Book& x) const {
        return id<x.id;
    }
};
vector<Book> vB;
int main() {
    int n;
    cin >> n;
    int ID;
    string title, author, keyword, publisher, year;
    for (int i = 0; i < n; ++i) {
        cin >> ID;
        getchar();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keyword);
        getline(cin, publisher);
        cin >> year;
        vB.push_back(Book(ID, title, author, keyword, publisher, year));
    }
    sort(vB.begin(), vB.end());
    int M;
    cin >> M;
    int sign;
    string key;
    for (int i = 0; i < M; ++i) {
        cin >> sign;
        cin.ignore(2);
        getline(cin, key);
        bool f = 1;
        cout << sign << ": " << key << endl;
        for (int i = 0; i < vB.size(); ++i) {
            switch (sign) {
            case 1:
                if (key == vB[i].title) {
                    printf("%07d\n", vB[i].id);
                    f = 0;
                }
                break;
            case 2:
                if (key == vB[i].author) {
                    printf("%07d\n", vB[i].id);
                    f = 0;
                }
                break;
            case 3:
                if (vB[i].keyword.find(key) != -1) {
                    printf("%07d\n", vB[i].id);
                    f = 0;
                }
                break;
            case 4:
                if (key == vB[i].publisher) {
                    printf("%07d\n", vB[i].id);
                    f = 0;
                }
                break;
            case 5:
                if (key == vB[i].year) {
                    printf("%07d\n", vB[i].id);
                    f = 0;
                }
                break;
            }
        }
        if (f) cout << "Not Found" << endl;
    }
    //system("pause");
        return 0;
}
————————————————
版权声明：本文为CSDN博主「Cute_jinx」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/cute_jinx/article/details/81300767