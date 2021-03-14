#include <iostream>
using namespace std;

const int N = 21;
int n;
string word[N];
int g[N][N];
int used[N];
int res;

void dfs(string s, int cur) {
    res = max((int) s.size(), res);
    used[cur]++;

    for (int i = 0; i < n; i++)
        if (g[cur][i] && used[i] < 2)
            dfs(s + word[i].substr(g[cur][i]), i);

    used[cur]--;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> word[i];

    char st;
    cin >> st;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            string a = word[i], b = word[j];
            for (int k = 1; k < min(a.size(), b.size()); k++)
                if (a.substr(a.size() - k) == b.substr(0, k)) {
                    g[i][j] = k;
                    break;
                }
        }

    for (int i = 0; i < n; i++)
        if (word[i][0] == st)
            dfs(word[i], i);

    cout << res << endl;

    return 0;
}