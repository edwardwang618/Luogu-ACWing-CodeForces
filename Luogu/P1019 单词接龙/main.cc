#include <iostream>
using namespace std;

const int N = 30;
string ss[N], start;
int vis[N], len, n;

int link(string s1, string s2) {
    for (int i = 1; i < min(s1.size(), s2.size()); i++)
        if (s1.substr(s1.size() - i) == s2.substr(0, i)) return i;
    
    return 0;
}

void dfs(string s, int cur_len) {
    len = max(len, cur_len);
    for (int i = 1; i <= n; i++) {
        if (vis[i] >= 2) continue;
        int overlap;
        if (overlap = link(s, ss[i])) {
            vis[i]++;
            dfs(ss[i], cur_len + ss[i].size() - overlap);
            vis[i]--;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) cin >> ss[i];
    cin >> start;

    dfs(s, 1);
    printf("%d\n", len);
    return 0;
}