#include <iostream>
#include <queue>
using namespace std;

const int N = 15;
int n;
int l[N], r[N];
bool st[N];
string res;

void flip(int cur) {
    if (cur == -1) return;
    int tmp = l[cur];
    l[cur] = r[cur];
    r[cur] = tmp;

    flip(l[cur]);
    flip(r[cur]);
}

void bfs(int root) {
    if (root == -1) return;
    queue<int> q;
    q.push(root);
    while (q.size()) {
        int t = q.front(); q.pop();
        res += to_string(t) + " ";
        if (l[t] != -1) q.push(l[t]);
        if (r[t] != -1) q.push(r[t]);
    }
}

void dfs(int root) {
    if (root == -1) return;
    dfs(l[root]);
    res += to_string(root) + " ";
    dfs(r[root]);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        char left, right;
        cin >> left >> right;
        if (left != '-') {
            l[i] = left - '0';
            st[l[i]] = true;
        } else l[i] = -1;
        if (right != '-') {
            r[i] = right - '0';
            st[r[i]] = true;
        } else r[i] = -1;
    }

    int root = -1;
    for (int i = 0; i < n; i++)
        if (!st[i]) root = i;

    flip(root);

    bfs(root);
    res.pop_back();
    cout << res << endl;

    res = "";
    dfs(root);
    res.pop_back();
    cout << res << endl;

    return 0;
}