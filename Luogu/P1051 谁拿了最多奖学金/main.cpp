#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int qimo;
    int pingyi;
    bool ganbu;
    bool xibu;
    int lunwen;
    int jiangjin = 0;
};

int main() {
    int N;
    cin >> N;

    Student no1;
    no1.jiangjin = 0;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        Student s;
        cin >> s.name >> s.qimo >> s.pingyi;
        string bo;
        cin >> bo;
        if (bo == "Y") s.ganbu = true;
        else s.ganbu = false;
        cin >> bo;
        if (bo == "Y") s.xibu = true;
        else s.xibu = false;

        cin >> s.lunwen;
        if (s.qimo > 80 && s.lunwen >= 1) s.jiangjin += 8000;
        if (s.qimo > 85 && s.pingyi > 80) s.jiangjin += 4000;
        if (s.qimo > 90) s.jiangjin += 2000;
        if (s.qimo > 85 && s.xibu) s.jiangjin += 1000;
        if (s.pingyi > 80 && s.ganbu) s.jiangjin += 850;
        sum += s.jiangjin;
        if (s.jiangjin > no1.jiangjin) no1 = s;
    }

    cout << no1.name << endl << no1.jiangjin << endl << sum << endl;

    return 0;
}