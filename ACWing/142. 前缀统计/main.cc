#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n, m;
int son[N][26], cnt[N];
char s[N];
int idx;

void insert(string s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }

    cnt[p]++;
}

int query(string s) {
    int p = 0, res = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (son[p][u]) p = son[p][u];
        else break;

        res += cnt[p];
    }

    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    while (n--) {
        cin >> s;
        insert(s);
    }
    
    while (m--) {
        cin >> s;
        printf("%d\n", query(s));
    }

    return 0;
}