#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    int yuwen;
    int shuxue;
    int yingyu;
    int zongfen;
} stus[305];

bool comp(Student s1, Student s2) {
    if (s1.zongfen != s2.zongfen) return s1.zongfen > s2.zongfen;
    else if (s1.yuwen != s2.yuwen) return s1.yuwen > s2.yuwen;
    else return s1.id < s2.id;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        stus[i].id = i + 1;
        cin >> stus[i].yuwen >> stus[i].shuxue >> stus[i].yingyu;
        stus[i].zongfen = stus[i].yuwen + stus[i].shuxue + stus[i].yingyu;
    }

    sort(stus, stus + n, comp);
    for (int i = 0; i < 5; i++) {
        cout << stus[i].id << " " << stus[i].zongfen << endl;
    }

    return 0;
}