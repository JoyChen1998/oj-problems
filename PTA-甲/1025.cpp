#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct student
{
    string id;
    int score;
    int loc;
    int loc_rank;
    int total_rank;
}stu[30005];
bool cmp(student a, student b)
{
    if(a.score != b.score) return a.score > b.score;
    else return a.id < b.id;
}
int main()
{
    int num = 0;//学生总数
    int numloc;
    cin >> numloc;
    for(int i = 1; i <= numloc; i++)
    {
        int numpart;
        cin >> numpart;
        for(int j = 0; j < numpart; j++)
        {
            cin >> stu[num].id >> stu[num].score;
            stu[num].loc = i;
            num++;
        }
        sort(stu + num - numpart, stu + num, cmp);
        stu[num - numpart].loc_rank = 1;
        for(int j = num - numpart + 1; j < num; j++)
        {
            if(stu[j].score == stu[j - 1].score) stu[j].loc_rank = stu[j - 1].loc_rank;
            else stu[j].loc_rank = j + 1 - (num - numpart);
        }

    }
    cout << num << endl;
    sort(stu, stu + num, cmp);
    stu[0].total_rank = 1;
    cout << stu[0].id << " " << stu[0].total_rank << " " << stu[0].loc << " " << stu[0].loc_rank << endl;
    for(int i = 1; i < num; i++)
    {
        cout << stu[i].id << " ";
        if(stu[i].score == stu[i - 1].score) stu[i].total_rank = stu[i - 1].total_rank;
        else stu[i].total_rank = i + 1;
        cout << stu[i].total_rank;
        cout << " " << stu[i].loc << " " << stu[i].loc_rank << endl;
    }
    return 0;
}