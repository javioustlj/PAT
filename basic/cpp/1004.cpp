#include<iostream>
#include<string>

using namespace std;

struct Student {
    string name;
    string ID;
    unsigned score{0};
};

int main(void)
{
    int n;
    cin >> n;
    Student stu[n];
    for (int i = 0; i != n; ++i)
        cin >> stu[i].name >> stu[i].ID >> stu[i].score;

    Student *minStudent{&stu[0]}, *maxStudent{&stu[0]};
    for (int i = 0; i != n; ++i) {
        if (stu[i].score > maxStudent->score)
            maxStudent = &stu[i];
        if (stu[i].score < minStudent->score)
            minStudent = &stu[i];
    }

    cout << maxStudent->name << ' ' << maxStudent->ID << endl;
    cout << minStudent->name << ' ' << minStudent->ID << endl;

    return 0;
}
