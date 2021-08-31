#include <iostream>
#include <algorithm>
using namespace std;

const int N = 15;
string s, s1, s2;
int ne[N];

void build_next(string& p) {
    for (int i = 0, j = ne[0] = -1; i < p.size() - 1; ) {
        if (j == -1 || p[i] == p[j]) {
            i++;
            j++;
            ne[i] = p[i] != p[j] ? j : ne[j];
        } else j = ne[j];
    }
}

int find(string& p) {
    for (int i = 0, j = 0; i < s.size(); ) {
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        } else j = ne[j];

        if (j == p.size()) return i - j;
    }

    return -1;
}

int main() {
    char ch;
    while (cin >> ch, ch != ',') s += ch;
    while (cin >> ch, ch != ',') s1 += ch;
    while (cin >> ch) s2 += ch;

    build_next(s1);
    int l = find(s1);
    if (l == -1) {
        puts("-1");
        return 0;
    }
    reverse(s.begin(), s.end());
    reverse(s2.begin(), s2.end());
    build_next(s2);
    int r = find(s2);
    if (r == -1) {
        puts("-1");
        return 0;
    }

    r = s.size() - r - s2.size();
    l += s1.size() - 1;
    if (l >= r) puts("-1");
    else printf("%d\n", r - l - 1);

    return 0;
}