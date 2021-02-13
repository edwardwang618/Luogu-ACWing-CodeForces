#include <iostream>
#include <vector>
using namespace std;

void dfs(int n, vector<int>& v, bool used[]) {
    if (v.size() == n) {
        for (int i = 0; i < n; i++) cout << v[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            v.push_back(i + 1);
            used[i] = true;
            dfs(n, v, used);
            v.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int n;
    cin >> n;

    bool used[n];
    memset(used, false, sizeof used);

    vector<int> v;
    dfs(n, v, used);

    return 0;
}