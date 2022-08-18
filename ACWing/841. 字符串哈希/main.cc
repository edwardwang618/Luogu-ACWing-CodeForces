#include <iostream>
#include <string>
using namespace std;

const int N = 100010;
long h[N], p[N];
const long P = 131;

long ha(int l, int r) {
    return h[r + 1] - h[l] * p[r - l + 1];
}

int main() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    p[0] = 1;
    for (int i = 0; i < s.length(); i++) {
        h[i + 1] = h[i] * P + s[i];
        p[i + 1] = p[i] * P;
    }

    while (m--) {
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (ha(l1 - 1, r1 - 1) == ha(l2 - 1, r2 - 1)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}