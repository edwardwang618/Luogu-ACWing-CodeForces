#include <iostream>
#include <vector>

using namespace std;
using PII = pair<int, int>;

vector<int> a;
vector<PII> res1, res;

void op(int x, int y) {
    a[x] = ~a[x] & ((1 << 4) - 1);
    for (int i = 0; i < 4; i++) {
        if (i == x) continue;
        a[i] ^= 1 << 3 - y;
    }
}

bool dfs(int x, int y) {
    if (y == 4) {
        if (x == 3) {
            if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) {
                if (res.empty() || res1.size() < res.size()) res = res1;
                return true;
            } else return false;
        } else return dfs(x + 1, 0);
    }

    op(x, y);
    res1.push_back({x, y});
    if (dfs(x, y + 1)) return true;
    op(x, y);
    res1.pop_back();

    if (dfs(x, y + 1)) return true;
    return false;
}

int main() {
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        int x = 0;
        for (char ch: s) {
            x <<= 1;
            if (ch == '+') x |= 1;
        }
        a.push_back(x);
    }

    dfs(0, 0);
    printf("%d\n", (int) res.size());
    for (auto s: res)
        printf("%d %d\n", s.first + 1, s.second + 1);

    return 0;
}